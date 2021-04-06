#!/usr/bin/env python3

import argparse, os, re, shutil, stat, subprocess, sys, tempfile

def main():
    scriptdir = os.path.dirname(os.path.realpath(__file__))
    # TODO: auto-parameterize this?
    stubbase = "onekpaq_stub_lnx32.asm"

    parser = argparse.ArgumentParser()

    parser.add_argument('--onekpaq', default=scriptdir+"/onekpaq_encode",
        help="The onekpaq_encode binary to use")
    parser.add_argument('--nasm', default=os.getenv('NASM') or shutil.which('nasm'),
        help="The nasm binary to use")
    parser.add_argument('--stub', default=scriptdir+"/"+stubbase,
        help="The assembly decompressor stub to use")

    parser.add_argument('mode', choices=[1,2,3,4], type=int,
        help="Selects the compression and decompression mode: "\
            +"'1' is 'single block, small decoder', "\
            +"'2' is 'multi-block, small decoder', "\
            +"'3' is 'single block, fast decoder', "\
            +"'4' is 'multi-block, fast decoder'.")
    parser.add_argument('complexity', choices=[1,2,3], type=int,
        help="Compression complexity to use. Higher values "+\
             "mean higher compression, but also longer compression times.")
    parser.add_argument('input', nargs='+', help="Input block(s)")
    parser.add_argument('output', type=str, help="Output executable")

    args = parser.parse_args()

    with tempfile.NamedTemporaryFile(prefix="onekpaq") as tf:
        okpargs = [args.onekpaq, str(args.mode), str(args.complexity),
                   *args.input, tf.name]
        #print(okpargs)
        proc = subprocess.Popen(okpargs, stdout=subprocess.PIPE,
                                stderr=sys.stderr, cwd=scriptdir)
        (sout, serr_) = proc.communicate()
        sys.stderr.buffer.write(sout)
        sys.stderr.buffer.flush()
        if proc.returncode != 0:
            print("oneKpaq compressor failed.")
            return proc.returncode

        out = sout.decode('utf-8')
        match = re.search('P offset=([0-9]+) shift=([0-9]+)', out)
        assert match is not None
        offset, shift = (int(match.group(1)), int(match.group(2)))
        #print(offset, shift)

        #print(tf.name)
        nasmargs = [args.nasm, "-fbin", "-o", args.output,
                    args.stub, "-DPAYLOAD_OFF=%d" % offset,
                    "-DONEKPAQ_DECOMPRESSOR_MODE=%d" % args.mode,
                    "-DONEKPAQ_DECOMPRESSOR_SHIFT=%d" % shift,
                    "-DPAYLOAD_BIN=\"%s\"" % tf.name]
        #print(nasmargs)
        subprocess.run(nasmargs, check=True)
        os.chmod(args.output, os.stat(args.output).st_mode|stat.S_IEXEC)
        wcargs = ["wc","-c",args.output]
        subprocess.run(wcargs, check=True)


        return 0


if __name__ == '__main__':
    rv = main()
    if rv is None: pass
    else:
        try: sys.exit(int(rv))
        except Exception: sys.exit(1)

