   1               		.file	"beam.cpp"
   2               	__SP_H__ = 0x3e
   3               	__SP_L__ = 0x3d
   4               	__SREG__ = 0x3f
   5               	__tmp_reg__ = 0
   6               	__zero_reg__ = 1
   7               		.text
   8               	.Ltext0:
   9               		.cfi_sections	.debug_frame
  10               	.global	_ZN4Beam7map_redEPh
  12               	_ZN4Beam7map_redEPh:
  13               	.LFB0:
  14               		.file 1 "beam.cpp"
   1:beam.cpp      **** //
   2:beam.cpp      **** // Created by Garth Webb on 3/8/18.
   3:beam.cpp      **** //
   4:beam.cpp      **** 
   5:beam.cpp      **** #include "beam.h"
   6:beam.cpp      **** 
   7:beam.cpp      **** void Beam::map_red(uint8_t *device_value) {
  15               		.loc 1 7 0
  16               		.cfi_startproc
  17               	.LVL0:
  18               	/* prologue: function */
  19               	/* frame size = 0 */
  20               	/* stack size = 0 */
  21               	.L__stack_usage = 0
   8:beam.cpp      ****     _red = device_value;
  22               		.loc 1 8 0
  23 0000 FC01      		movw r30,r24
  24 0002 7183      		std Z+1,r23
  25 0004 6083      		st Z,r22
  26 0006 0895      		ret
  27               		.cfi_endproc
  28               	.LFE0:
  30               	.global	_ZN4Beam9map_greenEPh
  32               	_ZN4Beam9map_greenEPh:
  33               	.LFB1:
   9:beam.cpp      **** }
  10:beam.cpp      **** 
  11:beam.cpp      **** void Beam::map_green(uint8_t *device_value) {
  34               		.loc 1 11 0
  35               		.cfi_startproc
  36               	.LVL1:
  37               	/* prologue: function */
  38               	/* frame size = 0 */
  39               	/* stack size = 0 */
  40               	.L__stack_usage = 0
  12:beam.cpp      ****     _green = device_value;
  41               		.loc 1 12 0
  42 0008 FC01      		movw r30,r24
  43 000a 7383      		std Z+3,r23
  44 000c 6283      		std Z+2,r22
  45 000e 0895      		ret
  46               		.cfi_endproc
  47               	.LFE1:
  49               	.global	_ZN4Beam8map_blueEPh
  51               	_ZN4Beam8map_blueEPh:
  52               	.LFB2:
  13:beam.cpp      **** }
  14:beam.cpp      **** void Beam::map_blue(uint8_t *device_value) {
  53               		.loc 1 14 0
  54               		.cfi_startproc
  55               	.LVL2:
  56               	/* prologue: function */
  57               	/* frame size = 0 */
  58               	/* stack size = 0 */
  59               	.L__stack_usage = 0
  15:beam.cpp      ****     _blue = device_value;
  60               		.loc 1 15 0
  61 0010 FC01      		movw r30,r24
  62 0012 7583      		std Z+5,r23
  63 0014 6483      		std Z+4,r22
  64 0016 0895      		ret
  65               		.cfi_endproc
  66               	.LFE2:
  68               	.global	_ZN4Beam7set_rgbEhhh
  70               	_ZN4Beam7set_rgbEhhh:
  71               	.LFB3:
  16:beam.cpp      **** }
  17:beam.cpp      **** 
  18:beam.cpp      **** void Beam::set_rgb(uint8_t red, uint8_t green, uint8_t blue) {
  72               		.loc 1 18 0
  73               		.cfi_startproc
  74               	.LVL3:
  75               	/* prologue: function */
  76               	/* frame size = 0 */
  77               	/* stack size = 0 */
  78               	.L__stack_usage = 0
  79 0018 FC01      		movw r30,r24
  19:beam.cpp      ****     *_red = red;
  80               		.loc 1 19 0
  81 001a A081      		ld r26,Z
  82 001c B181      		ldd r27,Z+1
  83 001e 6C93      		st X,r22
  20:beam.cpp      ****     *_green = green;
  84               		.loc 1 20 0
  85 0020 A281      		ldd r26,Z+2
  86 0022 B381      		ldd r27,Z+3
  87 0024 4C93      		st X,r20
  21:beam.cpp      ****     *_blue = blue;
  88               		.loc 1 21 0
  89 0026 0480      		ldd __tmp_reg__,Z+4
  90 0028 F581      		ldd r31,Z+5
  91 002a E02D      		mov r30,__tmp_reg__
  92 002c 2083      		st Z,r18
  93 002e 0895      		ret
  94               		.cfi_endproc
  95               	.LFE3:
  97               	.Letext0:
  98               		.file 2 "beam.h"
  99               		.file 3 "/opt/local/avr/include/stdint.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 beam.cpp
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:2      *ABS*:000000000000003e __SP_H__
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:3      *ABS*:000000000000003d __SP_L__
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:4      *ABS*:000000000000003f __SREG__
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:5      *ABS*:0000000000000000 __tmp_reg__
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:6      *ABS*:0000000000000001 __zero_reg__
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:12     .text:0000000000000000 _ZN4Beam7map_redEPh
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:32     .text:0000000000000008 _ZN4Beam9map_greenEPh
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:51     .text:0000000000000010 _ZN4Beam8map_blueEPh
/var/folders/h3/dpbt5kf17wx_4jnjxpvsf8zc0000gn/T//ccQfYBC4.s:70     .text:0000000000000018 _ZN4Beam7set_rgbEhhh

NO UNDEFINED SYMBOLS
