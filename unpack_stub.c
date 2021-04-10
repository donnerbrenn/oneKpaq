#include <stdint.h>
#include <stdbool.h>


void _start()

{
  unsigned int *puVar1;
  unsigned char *pbVar2;
  unsigned char *pbVar3;
  char cVar4;
  code *pcVar5;
  unsigned int uVar6;
  unsigned char bVar7;
  unsigned int uVar8;
  unsigned int uVar9;
  unsigned int uVar10;
  unsigned int uVar11;
  unsigned char bVar13;
  unsigned int uVar12;
  unsigned int uVar14;
  unsigned char *pbVar15;
  unsigned int *puVar16;
  unsigned int unaff_EBP;
  unsigned int uVar17;
  unsigned char *pbVar18;
  unsigned char *pbVar19;
  unsigned char *pbVar20;
  unsigned char *pbVar21;
  bool bVar22;
  bool bVar23;
  float fVar24;
  
  puVar16 = (unsigned int *)&DAT_0804811c;
  pbVar19 = &DAT_08048c57;
  uVar8 = DAT_08048c53 + 1;
  uVar17 = uVar8;
  do {
    uVar10 = uVar17;
    puVar1 = puVar16 + 1;
    cVar4 = *(char *)puVar1;
    *(char *)puVar1 = *(char *)puVar1 << 1;
    bVar22 = cVar4 < '\0';
    if (*(char *)puVar1 == '\0') {
      pbVar15 = (unsigned char *)((int)puVar16 + 5);
      bVar22 = (char)*pbVar15 < '\0';
      *pbVar15 = *pbVar15 << 1 | cVar4 < '\0';
      puVar16 = (unsigned int *)((int)puVar16 + 1);
    }
    unaff_EBP = unaff_EBP << 1 | (unsigned int)bVar22;
    while( true ) {
      uVar17 = uVar10 * 2;
      if (-1 < (int)uVar17) break;
      fVar24 = (float)1;
      uVar11 = uVar17 & 0xffffff00 | (unsigned int)(unsigned char)-CARRY4(uVar10,uVar10);
      uVar17 = uVar8;
      pbVar15 = &DAT_0804811f;
      do {
        uVar17 = (unsigned int)CONCAT11(*pbVar15,(char)uVar17);
        uVar14 = (int)uVar11 >> 0x1f;
        *puVar16 = uVar14;
        uVar9 = uVar11;
        uVar6 = uVar17;
        pbVar18 = pbVar19;
        pbVar21 = &DAT_08048c60;
        pbVar20 = &DAT_08048c60;
LAB_08048085:
        do {
          uVar12 = uVar6;
          pbVar3 = pbVar21 + 1;
          pbVar2 = pbVar18 + 1;
          bVar23 = *pbVar18 == *pbVar21;
          bVar22 = (uVar12 & 0x100) != 0;
          bVar13 = (unsigned char)uVar12;
          if (bVar22 || bVar23) {
            bVar7 = (char)uVar9 + 0x60;
            uVar9 = (unsigned int)bVar7;
            uVar6 = (unsigned int)CONCAT11((unsigned char)(uVar12 >> 8) >> 1 | (*pbVar18 < *pbVar21) << 7,bVar13);
            pbVar18 = pbVar2;
            pbVar21 = pbVar3;
            if (bVar7 != 0) goto LAB_08048085;
            bVar7 = *pbVar2;
            bVar7 = (bVar7 << (bVar13 & 7) | bVar7 >> 8 - (bVar13 & 7)) ^ *pbVar3;
            bVar22 = (uVar12 & 0x1f) != 0 && (bVar7 >> (bVar13 & 0x1f) - 1 & 1) != 0;
            bVar23 = (uVar12 & 0x1f) != 0;
            bVar23 = !bVar23 && bVar7 == 0 || bVar23 && bVar7 >> (bVar13 & 0x1f) == 0;
          }
          if (bVar23) {
            uVar14 = uVar14 - 1;
            *puVar16 = *puVar16 - 1;
            if (bVar22) {
              *puVar16 = (int)*puVar16 >> 1;
            }
            else {
              uVar14 = (int)uVar14 >> 1;
            }
          }
          pbVar21 = pbVar20 + 1;
          uVar9 = uVar11;
          uVar6 = uVar17;
          pbVar18 = pbVar19;
          pbVar20 = pbVar21;
        } while (pbVar21 < pbVar19);
        do {
          *puVar16 = *puVar16 << 4 | *puVar16 >> 0x1c;
          fVar24 = (float)*puVar16 / fVar24;
          *puVar16 = uVar14;
          uVar9 = uVar9 - 1;
        } while ((POPCOUNT(uVar9 & 0xff) & 1U) == 0);
        do {
          pbVar15 = pbVar15 + -1;
          bVar13 = (unsigned char)(uVar17 >> 8);
          if (bVar13 < *pbVar15) break;
          fVar24 = SQRT(fVar24);
        } while (bVar13 < *pbVar15 || bVar13 == *pbVar15);
      } while ((unsigned char)-CARRY4(uVar10,uVar10) != *pbVar15);
      *puVar16 = uVar10 & 0x7fffffff;
      *puVar16 = (int)ROUND((float)*puVar16 / (fVar24 + (float)1));
      uVar10 = (uVar10 & 0x7fffffff) - *puVar16;
      bVar22 = unaff_EBP == uVar10;
      uVar17 = unaff_EBP;
      uVar11 = uVar10;
      if (uVar10 < unaff_EBP) {
        uVar11 = uVar10 + 1;
        uVar17 = unaff_EBP - uVar11;
        bVar22 = uVar17 == 0;
        uVar10 = *puVar16;
      }
      pbVar19[8] = pbVar19[8] << 1 | unaff_EBP < uVar11;
      uVar8 = uVar8 - 1;
      if (uVar8 == 0) {
        pbVar19 = pbVar19 + 1;
        bVar22 = pbVar19 == (unsigned char *)0x0;
        uVar8 = 8;
      }
      unaff_EBP = uVar17;
      if (bVar22) {//syscalls... why???
        // pcVar5 = (code *)swi(0x80);
        // (*pcVar5)();
        // pcVar5 = (code *)swi(0x80);
        // (*pcVar5)();
        // pcVar5 = (code *)swi(0x80);
        // (*pcVar5)();
        // pcVar5 = (code *)swi(3);
        // (*pcVar5)();
        return;
      }
    }
  } while( true );
}
