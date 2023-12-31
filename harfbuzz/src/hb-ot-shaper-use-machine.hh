
#line 1 "hb-ot-shaper-use-machine.rl"
/*
 * Copyright © 2015  Mozilla Foundation.
 * Copyright © 2015  Google, Inc.
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Mozilla Author(s): Jonathan Kew
 * Google Author(s): Behdad Esfahbod
 */

#ifndef HB_OT_SHAPER_USE_MACHINE_HH
#define HB_OT_SHAPER_USE_MACHINE_HH

#include "hb.hh"

#include "hb-ot-shaper-syllabic.hh"

/* buffer var allocations */
#define use_category() ot_shaper_var_u8_category()

#define USE(Cat) use_syllable_machine_ex_##Cat

enum use_syllable_type_t {
  use_virama_terminated_cluster,
  use_sakot_terminated_cluster,
  use_standard_cluster,
  use_number_joiner_terminated_cluster,
  use_numeral_cluster,
  use_symbol_cluster,
  use_hieroglyph_cluster,
  use_broken_cluster,
  use_non_cluster,
};


#line 57 "hb-ot-shaper-use-machine.hh"
#define use_syllable_machine_ex_B 1u
#define use_syllable_machine_ex_CGJ 6u
#define use_syllable_machine_ex_CMAbv 31u
#define use_syllable_machine_ex_CMBlw 32u
#define use_syllable_machine_ex_CS 43u
#define use_syllable_machine_ex_FAbv 24u
#define use_syllable_machine_ex_FBlw 25u
#define use_syllable_machine_ex_FMAbv 45u
#define use_syllable_machine_ex_FMBlw 46u
#define use_syllable_machine_ex_FMPst 47u
#define use_syllable_machine_ex_FPst 26u
#define use_syllable_machine_ex_G 49u
#define use_syllable_machine_ex_GB 5u
#define use_syllable_machine_ex_H 12u
#define use_syllable_machine_ex_HN 13u
#define use_syllable_machine_ex_HVM 53u
#define use_syllable_machine_ex_IS 44u
#define use_syllable_machine_ex_J 50u
#define use_syllable_machine_ex_MAbv 27u
#define use_syllable_machine_ex_MBlw 28u
#define use_syllable_machine_ex_MPre 30u
#define use_syllable_machine_ex_MPst 29u
#define use_syllable_machine_ex_N 4u
#define use_syllable_machine_ex_O 0u
#define use_syllable_machine_ex_R 18u
#define use_syllable_machine_ex_SB 51u
#define use_syllable_machine_ex_SE 52u
#define use_syllable_machine_ex_SMAbv 41u
#define use_syllable_machine_ex_SMBlw 42u
#define use_syllable_machine_ex_SUB 11u
#define use_syllable_machine_ex_Sk 48u
#define use_syllable_machine_ex_VAbv 33u
#define use_syllable_machine_ex_VBlw 34u
#define use_syllable_machine_ex_VMAbv 37u
#define use_syllable_machine_ex_VMBlw 38u
#define use_syllable_machine_ex_VMPre 23u
#define use_syllable_machine_ex_VMPst 39u
#define use_syllable_machine_ex_VPre 22u
#define use_syllable_machine_ex_VPst 35u
#define use_syllable_machine_ex_WJ 16u
#define use_syllable_machine_ex_ZWNJ 14u


#line 101 "hb-ot-shaper-use-machine.hh"
static const unsigned char _use_syllable_machine_trans_keys[] = {
	0u, 53u, 11u, 53u, 11u, 53u, 1u, 53u, 14u, 48u, 14u, 47u, 14u, 47u, 14u, 47u, 
	14u, 46u, 14u, 46u, 14u, 14u, 14u, 48u, 14u, 48u, 14u, 48u, 1u, 14u, 14u, 48u, 
	14u, 53u, 14u, 53u, 14u, 53u, 14u, 53u, 12u, 53u, 14u, 53u, 12u, 53u, 12u, 53u, 
	12u, 53u, 11u, 53u, 1u, 14u, 1u, 48u, 11u, 53u, 14u, 42u, 14u, 42u, 11u, 53u, 
	11u, 53u, 1u, 53u, 14u, 48u, 14u, 47u, 14u, 47u, 14u, 47u, 14u, 46u, 14u, 46u, 
	14u, 14u, 14u, 48u, 14u, 48u, 14u, 48u, 1u, 14u, 14u, 48u, 14u, 53u, 14u, 53u, 
	14u, 53u, 14u, 53u, 12u, 53u, 14u, 53u, 12u, 53u, 12u, 53u, 12u, 53u, 11u, 53u, 
	1u, 14u, 1u, 14u, 1u, 48u, 13u, 14u, 4u, 14u, 11u, 53u, 11u, 53u, 1u, 53u, 
	14u, 48u, 14u, 47u, 14u, 47u, 14u, 47u, 14u, 46u, 14u, 46u, 14u, 14u, 14u, 48u, 
	14u, 48u, 14u, 48u, 1u, 14u, 14u, 48u, 14u, 53u, 14u, 53u, 14u, 53u, 14u, 53u, 
	12u, 53u, 14u, 53u, 12u, 53u, 12u, 53u, 12u, 53u, 11u, 53u, 1u, 14u, 1u, 14u, 
	1u, 48u, 11u, 53u, 11u, 53u, 1u, 53u, 14u, 48u, 14u, 47u, 14u, 47u, 14u, 47u, 
	14u, 46u, 14u, 46u, 14u, 14u, 14u, 48u, 14u, 48u, 14u, 48u, 1u, 14u, 14u, 48u, 
	14u, 53u, 14u, 53u, 14u, 53u, 14u, 53u, 12u, 53u, 14u, 53u, 12u, 53u, 12u, 53u, 
	12u, 53u, 11u, 53u, 1u, 14u, 1u, 48u, 4u, 14u, 13u, 14u, 1u, 53u, 11u, 53u, 
	14u, 42u, 14u, 42u, 1u, 5u, 14u, 52u, 14u, 52u, 14u, 51u, 0
};

static const char _use_syllable_machine_key_spans[] = {
	54, 43, 43, 53, 35, 34, 34, 34, 
	33, 33, 1, 35, 35, 35, 14, 35, 
	40, 40, 40, 40, 42, 40, 42, 42, 
	42, 43, 14, 48, 43, 29, 29, 43, 
	43, 53, 35, 34, 34, 34, 33, 33, 
	1, 35, 35, 35, 14, 35, 40, 40, 
	40, 40, 42, 40, 42, 42, 42, 43, 
	14, 14, 48, 2, 11, 43, 43, 53, 
	35, 34, 34, 34, 33, 33, 1, 35, 
	35, 35, 14, 35, 40, 40, 40, 40, 
	42, 40, 42, 42, 42, 43, 14, 14, 
	48, 43, 43, 53, 35, 34, 34, 34, 
	33, 33, 1, 35, 35, 35, 14, 35, 
	40, 40, 40, 40, 42, 40, 42, 42, 
	42, 43, 14, 48, 11, 2, 53, 43, 
	29, 29, 5, 39, 39, 38
};

static const short _use_syllable_machine_index_offsets[] = {
	0, 55, 99, 143, 197, 233, 268, 303, 
	338, 372, 406, 408, 444, 480, 516, 531, 
	567, 608, 649, 690, 731, 774, 815, 858, 
	901, 944, 988, 1003, 1052, 1096, 1126, 1156, 
	1200, 1244, 1298, 1334, 1369, 1404, 1439, 1473, 
	1507, 1509, 1545, 1581, 1617, 1632, 1668, 1709, 
	1750, 1791, 1832, 1875, 1916, 1959, 2002, 2045, 
	2089, 2104, 2119, 2168, 2171, 2183, 2227, 2271, 
	2325, 2361, 2396, 2431, 2466, 2500, 2534, 2536, 
	2572, 2608, 2644, 2659, 2695, 2736, 2777, 2818, 
	2859, 2902, 2943, 2986, 3029, 3072, 3116, 3131, 
	3146, 3195, 3239, 3283, 3337, 3373, 3408, 3443, 
	3478, 3512, 3546, 3548, 3584, 3620, 3656, 3671, 
	3707, 3748, 3789, 3830, 3871, 3914, 3955, 3998, 
	4041, 4084, 4128, 4143, 4192, 4204, 4207, 4261, 
	4305, 4335, 4365, 4371, 4411, 4451
};

static const unsigned char _use_syllable_machine_indicies[] = {
	0, 1, 2, 2, 3, 4, 2, 2, 
	2, 2, 2, 5, 6, 7, 8, 2, 
	2, 2, 9, 2, 2, 2, 10, 11, 
	12, 13, 14, 15, 16, 17, 18, 19, 
	20, 21, 22, 23, 2, 24, 25, 26, 
	2, 27, 28, 29, 30, 31, 32, 33, 
	30, 34, 2, 35, 2, 36, 2, 38, 
	39, 37, 40, 37, 37, 37, 37, 37, 
	37, 37, 41, 42, 43, 44, 45, 46, 
	47, 48, 49, 50, 51, 52, 53, 54, 
	37, 55, 56, 57, 37, 58, 59, 37, 
	60, 61, 62, 63, 60, 37, 37, 37, 
	37, 64, 37, 38, 39, 37, 40, 37, 
	37, 37, 37, 37, 37, 37, 41, 42, 
	43, 44, 45, 46, 47, 48, 49, 51, 
	51, 52, 53, 54, 37, 55, 56, 57, 
	37, 37, 37, 37, 60, 61, 62, 63, 
	60, 37, 37, 37, 37, 64, 37, 38, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 40, 37, 37, 37, 
	37, 37, 37, 37, 37, 42, 43, 44, 
	45, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 55, 56, 57, 37, 37, 
	37, 37, 37, 61, 62, 63, 65, 37, 
	37, 37, 37, 42, 37, 40, 37, 37, 
	37, 37, 37, 37, 37, 37, 42, 43, 
	44, 45, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 55, 56, 57, 37, 
	37, 37, 37, 37, 61, 62, 63, 65, 
	37, 40, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 43, 44, 45, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	61, 62, 63, 37, 40, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 44, 
	45, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 61, 62, 63, 37, 40, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 45, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 61, 62, 
	63, 37, 40, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 61, 62, 37, 40, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 62, 37, 40, 37, 
	40, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 43, 44, 45, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 55, 
	56, 57, 37, 37, 37, 37, 37, 61, 
	62, 63, 65, 37, 40, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 43, 44, 
	45, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 56, 57, 37, 37, 
	37, 37, 37, 61, 62, 63, 65, 37, 
	40, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 43, 44, 45, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 57, 37, 37, 37, 37, 37, 61, 
	62, 63, 65, 37, 66, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 40, 37, 40, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 43, 44, 45, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 61, 62, 63, 65, 37, 40, 
	37, 37, 37, 37, 37, 37, 37, 41, 
	42, 43, 44, 45, 37, 37, 37, 37, 
	37, 37, 52, 53, 54, 37, 55, 56, 
	57, 37, 37, 37, 37, 37, 61, 62, 
	63, 65, 37, 37, 37, 37, 42, 37, 
	40, 37, 37, 37, 37, 37, 37, 37, 
	37, 42, 43, 44, 45, 37, 37, 37, 
	37, 37, 37, 52, 53, 54, 37, 55, 
	56, 57, 37, 37, 37, 37, 37, 61, 
	62, 63, 65, 37, 37, 37, 37, 42, 
	37, 40, 37, 37, 37, 37, 37, 37, 
	37, 37, 42, 43, 44, 45, 37, 37, 
	37, 37, 37, 37, 37, 53, 54, 37, 
	55, 56, 57, 37, 37, 37, 37, 37, 
	61, 62, 63, 65, 37, 37, 37, 37, 
	42, 37, 40, 37, 37, 37, 37, 37, 
	37, 37, 37, 42, 43, 44, 45, 37, 
	37, 37, 37, 37, 37, 37, 37, 54, 
	37, 55, 56, 57, 37, 37, 37, 37, 
	37, 61, 62, 63, 65, 37, 37, 37, 
	37, 42, 37, 67, 37, 40, 37, 37, 
	37, 37, 37, 37, 37, 41, 42, 43, 
	44, 45, 37, 47, 48, 37, 37, 37, 
	52, 53, 54, 37, 55, 56, 57, 37, 
	37, 37, 37, 37, 61, 62, 63, 65, 
	37, 37, 37, 37, 42, 37, 40, 37, 
	37, 37, 37, 37, 37, 37, 37, 42, 
	43, 44, 45, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 55, 56, 57, 
	37, 37, 37, 37, 37, 61, 62, 63, 
	65, 37, 37, 37, 37, 42, 37, 67, 
	37, 40, 37, 37, 37, 37, 37, 37, 
	37, 41, 42, 43, 44, 45, 37, 37, 
	48, 37, 37, 37, 52, 53, 54, 37, 
	55, 56, 57, 37, 37, 37, 37, 37, 
	61, 62, 63, 65, 37, 37, 37, 37, 
	42, 37, 67, 37, 40, 37, 37, 37, 
	37, 37, 37, 37, 41, 42, 43, 44, 
	45, 37, 37, 37, 37, 37, 37, 52, 
	53, 54, 37, 55, 56, 57, 37, 37, 
	37, 37, 37, 61, 62, 63, 65, 37, 
	37, 37, 37, 42, 37, 67, 37, 40, 
	37, 37, 37, 37, 37, 37, 37, 41, 
	42, 43, 44, 45, 46, 47, 48, 37, 
	37, 37, 52, 53, 54, 37, 55, 56, 
	57, 37, 37, 37, 37, 37, 61, 62, 
	63, 65, 37, 37, 37, 37, 42, 37, 
	38, 39, 37, 40, 37, 37, 37, 37, 
	37, 37, 37, 41, 42, 43, 44, 45, 
	46, 47, 48, 49, 37, 51, 52, 53, 
	54, 37, 55, 56, 57, 37, 37, 37, 
	37, 60, 61, 62, 63, 60, 37, 37, 
	37, 37, 64, 37, 38, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 40, 37, 38, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	40, 37, 37, 37, 37, 37, 37, 37, 
	37, 42, 43, 44, 45, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 55, 
	56, 57, 37, 37, 37, 37, 37, 61, 
	62, 63, 65, 37, 38, 39, 37, 40, 
	37, 37, 37, 37, 37, 37, 37, 41, 
	42, 43, 44, 45, 46, 47, 48, 49, 
	50, 51, 52, 53, 54, 37, 55, 56, 
	57, 37, 37, 37, 37, 60, 61, 62, 
	63, 60, 37, 37, 37, 37, 64, 37, 
	40, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 58, 59, 37, 40, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 37, 37, 37, 37, 37, 37, 
	37, 37, 59, 37, 69, 70, 68, 71, 
	68, 68, 68, 68, 68, 68, 68, 72, 
	73, 74, 75, 76, 77, 78, 79, 80, 
	1, 81, 82, 83, 84, 68, 85, 86, 
	87, 68, 68, 68, 68, 88, 89, 90, 
	91, 92, 68, 68, 68, 68, 93, 68, 
	69, 70, 68, 71, 68, 68, 68, 68, 
	68, 68, 68, 72, 73, 74, 75, 76, 
	77, 78, 79, 80, 81, 81, 82, 83, 
	84, 68, 85, 86, 87, 68, 68, 68, 
	68, 88, 89, 90, 91, 92, 68, 68, 
	68, 68, 93, 68, 69, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 68, 73, 74, 75, 76, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	85, 86, 87, 68, 68, 68, 68, 68, 
	89, 90, 91, 94, 68, 68, 68, 68, 
	73, 68, 71, 68, 68, 68, 68, 68, 
	68, 68, 68, 73, 74, 75, 76, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 85, 86, 87, 68, 68, 68, 68, 
	68, 89, 90, 91, 94, 68, 71, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	74, 75, 76, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 89, 90, 91, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 75, 76, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	89, 90, 91, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	76, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 89, 90, 91, 68, 71, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 89, 90, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 90, 68, 71, 68, 71, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 74, 
	75, 76, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 85, 86, 87, 68, 
	68, 68, 68, 68, 89, 90, 91, 94, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 74, 75, 76, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 86, 87, 68, 68, 68, 68, 68, 
	89, 90, 91, 94, 68, 71, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 74, 
	75, 76, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 87, 68, 
	68, 68, 68, 68, 89, 90, 91, 94, 
	68, 96, 95, 95, 95, 95, 95, 95, 
	95, 95, 95, 95, 95, 95, 97, 95, 
	71, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 74, 75, 76, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 89, 
	90, 91, 94, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 72, 73, 74, 75, 
	76, 68, 68, 68, 68, 68, 68, 82, 
	83, 84, 68, 85, 86, 87, 68, 68, 
	68, 68, 68, 89, 90, 91, 94, 68, 
	68, 68, 68, 73, 68, 71, 68, 68, 
	68, 68, 68, 68, 68, 68, 73, 74, 
	75, 76, 68, 68, 68, 68, 68, 68, 
	82, 83, 84, 68, 85, 86, 87, 68, 
	68, 68, 68, 68, 89, 90, 91, 94, 
	68, 68, 68, 68, 73, 68, 71, 68, 
	68, 68, 68, 68, 68, 68, 68, 73, 
	74, 75, 76, 68, 68, 68, 68, 68, 
	68, 68, 83, 84, 68, 85, 86, 87, 
	68, 68, 68, 68, 68, 89, 90, 91, 
	94, 68, 68, 68, 68, 73, 68, 71, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	73, 74, 75, 76, 68, 68, 68, 68, 
	68, 68, 68, 68, 84, 68, 85, 86, 
	87, 68, 68, 68, 68, 68, 89, 90, 
	91, 94, 68, 68, 68, 68, 73, 68, 
	98, 68, 71, 68, 68, 68, 68, 68, 
	68, 68, 72, 73, 74, 75, 76, 68, 
	78, 79, 68, 68, 68, 82, 83, 84, 
	68, 85, 86, 87, 68, 68, 68, 68, 
	68, 89, 90, 91, 94, 68, 68, 68, 
	68, 73, 68, 71, 68, 68, 68, 68, 
	68, 68, 68, 68, 73, 74, 75, 76, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 85, 86, 87, 68, 68, 68, 
	68, 68, 89, 90, 91, 94, 68, 68, 
	68, 68, 73, 68, 98, 68, 71, 68, 
	68, 68, 68, 68, 68, 68, 72, 73, 
	74, 75, 76, 68, 68, 79, 68, 68, 
	68, 82, 83, 84, 68, 85, 86, 87, 
	68, 68, 68, 68, 68, 89, 90, 91, 
	94, 68, 68, 68, 68, 73, 68, 98, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 72, 73, 74, 75, 76, 68, 68, 
	68, 68, 68, 68, 82, 83, 84, 68, 
	85, 86, 87, 68, 68, 68, 68, 68, 
	89, 90, 91, 94, 68, 68, 68, 68, 
	73, 68, 98, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 72, 73, 74, 75, 
	76, 77, 78, 79, 68, 68, 68, 82, 
	83, 84, 68, 85, 86, 87, 68, 68, 
	68, 68, 68, 89, 90, 91, 94, 68, 
	68, 68, 68, 73, 68, 69, 70, 68, 
	71, 68, 68, 68, 68, 68, 68, 68, 
	72, 73, 74, 75, 76, 77, 78, 79, 
	80, 68, 81, 82, 83, 84, 68, 85, 
	86, 87, 68, 68, 68, 68, 88, 89, 
	90, 91, 92, 68, 68, 68, 68, 93, 
	68, 69, 99, 99, 99, 99, 99, 99, 
	99, 99, 99, 99, 99, 99, 100, 99, 
	69, 95, 95, 95, 95, 95, 95, 95, 
	95, 95, 95, 95, 95, 97, 95, 69, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 68, 73, 74, 75, 
	76, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 85, 86, 87, 68, 68, 
	68, 68, 68, 89, 90, 91, 94, 68, 
	102, 103, 101, 3, 104, 104, 104, 104, 
	104, 104, 104, 104, 104, 105, 104, 106, 
	107, 68, 71, 68, 68, 68, 68, 68, 
	68, 68, 108, 109, 110, 111, 112, 113, 
	114, 115, 116, 117, 118, 119, 120, 121, 
	68, 122, 123, 124, 68, 58, 59, 68, 
	125, 126, 127, 128, 129, 68, 68, 68, 
	68, 130, 68, 106, 107, 68, 71, 68, 
	68, 68, 68, 68, 68, 68, 108, 109, 
	110, 111, 112, 113, 114, 115, 116, 118, 
	118, 119, 120, 121, 68, 122, 123, 124, 
	68, 68, 68, 68, 125, 126, 127, 128, 
	129, 68, 68, 68, 68, 130, 68, 106, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 68, 109, 110, 111, 
	112, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 122, 123, 124, 68, 68, 
	68, 68, 68, 126, 127, 128, 131, 68, 
	68, 68, 68, 109, 68, 71, 68, 68, 
	68, 68, 68, 68, 68, 68, 109, 110, 
	111, 112, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 122, 123, 124, 68, 
	68, 68, 68, 68, 126, 127, 128, 131, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 110, 111, 112, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	126, 127, 128, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 111, 
	112, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 126, 127, 128, 68, 71, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 112, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 126, 127, 
	128, 68, 71, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 126, 127, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 127, 68, 71, 68, 
	71, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 110, 111, 112, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 122, 
	123, 124, 68, 68, 68, 68, 68, 126, 
	127, 128, 131, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 110, 111, 
	112, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 123, 124, 68, 68, 
	68, 68, 68, 126, 127, 128, 131, 68, 
	71, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 110, 111, 112, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 124, 68, 68, 68, 68, 68, 126, 
	127, 128, 131, 68, 132, 95, 95, 95, 
	95, 95, 95, 95, 95, 95, 95, 95, 
	95, 97, 95, 71, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 110, 111, 112, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	68, 68, 126, 127, 128, 131, 68, 71, 
	68, 68, 68, 68, 68, 68, 68, 108, 
	109, 110, 111, 112, 68, 68, 68, 68, 
	68, 68, 119, 120, 121, 68, 122, 123, 
	124, 68, 68, 68, 68, 68, 126, 127, 
	128, 131, 68, 68, 68, 68, 109, 68, 
	71, 68, 68, 68, 68, 68, 68, 68, 
	68, 109, 110, 111, 112, 68, 68, 68, 
	68, 68, 68, 119, 120, 121, 68, 122, 
	123, 124, 68, 68, 68, 68, 68, 126, 
	127, 128, 131, 68, 68, 68, 68, 109, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 68, 109, 110, 111, 112, 68, 68, 
	68, 68, 68, 68, 68, 120, 121, 68, 
	122, 123, 124, 68, 68, 68, 68, 68, 
	126, 127, 128, 131, 68, 68, 68, 68, 
	109, 68, 71, 68, 68, 68, 68, 68, 
	68, 68, 68, 109, 110, 111, 112, 68, 
	68, 68, 68, 68, 68, 68, 68, 121, 
	68, 122, 123, 124, 68, 68, 68, 68, 
	68, 126, 127, 128, 131, 68, 68, 68, 
	68, 109, 68, 133, 68, 71, 68, 68, 
	68, 68, 68, 68, 68, 108, 109, 110, 
	111, 112, 68, 114, 115, 68, 68, 68, 
	119, 120, 121, 68, 122, 123, 124, 68, 
	68, 68, 68, 68, 126, 127, 128, 131, 
	68, 68, 68, 68, 109, 68, 71, 68, 
	68, 68, 68, 68, 68, 68, 68, 109, 
	110, 111, 112, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 122, 123, 124, 
	68, 68, 68, 68, 68, 126, 127, 128, 
	131, 68, 68, 68, 68, 109, 68, 133, 
	68, 71, 68, 68, 68, 68, 68, 68, 
	68, 108, 109, 110, 111, 112, 68, 68, 
	115, 68, 68, 68, 119, 120, 121, 68, 
	122, 123, 124, 68, 68, 68, 68, 68, 
	126, 127, 128, 131, 68, 68, 68, 68, 
	109, 68, 133, 68, 71, 68, 68, 68, 
	68, 68, 68, 68, 108, 109, 110, 111, 
	112, 68, 68, 68, 68, 68, 68, 119, 
	120, 121, 68, 122, 123, 124, 68, 68, 
	68, 68, 68, 126, 127, 128, 131, 68, 
	68, 68, 68, 109, 68, 133, 68, 71, 
	68, 68, 68, 68, 68, 68, 68, 108, 
	109, 110, 111, 112, 113, 114, 115, 68, 
	68, 68, 119, 120, 121, 68, 122, 123, 
	124, 68, 68, 68, 68, 68, 126, 127, 
	128, 131, 68, 68, 68, 68, 109, 68, 
	106, 107, 68, 71, 68, 68, 68, 68, 
	68, 68, 68, 108, 109, 110, 111, 112, 
	113, 114, 115, 116, 68, 118, 119, 120, 
	121, 68, 122, 123, 124, 68, 68, 68, 
	68, 125, 126, 127, 128, 129, 68, 68, 
	68, 68, 130, 68, 106, 99, 99, 99, 
	99, 99, 99, 99, 99, 99, 99, 99, 
	99, 100, 99, 106, 95, 95, 95, 95, 
	95, 95, 95, 95, 95, 95, 95, 95, 
	97, 95, 106, 68, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 68, 71, 
	68, 68, 68, 68, 68, 68, 68, 68, 
	109, 110, 111, 112, 68, 68, 68, 68, 
	68, 68, 68, 68, 68, 68, 122, 123, 
	124, 68, 68, 68, 68, 68, 126, 127, 
	128, 131, 68, 106, 107, 68, 71, 68, 
	68, 68, 68, 68, 68, 68, 108, 109, 
	110, 111, 112, 113, 114, 115, 116, 117, 
	118, 119, 120, 121, 68, 122, 123, 124, 
	68, 68, 68, 68, 125, 126, 127, 128, 
	129, 68, 68, 68, 68, 130, 68, 5, 
	6, 134, 8, 134, 134, 134, 134, 134, 
	134, 134, 10, 11, 12, 13, 14, 15, 
	16, 17, 18, 20, 20, 21, 22, 23, 
	134, 24, 25, 26, 134, 134, 134, 134, 
	30, 31, 32, 33, 30, 134, 134, 134, 
	134, 36, 134, 5, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	8, 134, 134, 134, 134, 134, 134, 134, 
	134, 11, 12, 13, 14, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 24, 
	25, 26, 134, 134, 134, 134, 134, 31, 
	32, 33, 135, 134, 134, 134, 134, 11, 
	134, 8, 134, 134, 134, 134, 134, 134, 
	134, 134, 11, 12, 13, 14, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	24, 25, 26, 134, 134, 134, 134, 134, 
	31, 32, 33, 135, 134, 8, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 12, 
	13, 14, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 31, 32, 33, 134, 
	8, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 13, 14, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 31, 
	32, 33, 134, 8, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 14, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 31, 32, 33, 134, 8, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 31, 32, 134, 
	8, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	32, 134, 8, 134, 8, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 12, 13, 
	14, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 24, 25, 26, 134, 134, 
	134, 134, 134, 31, 32, 33, 135, 134, 
	8, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 12, 13, 14, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	25, 26, 134, 134, 134, 134, 134, 31, 
	32, 33, 135, 134, 8, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 12, 13, 
	14, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 26, 134, 134, 
	134, 134, 134, 31, 32, 33, 135, 134, 
	136, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 8, 134, 8, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 12, 13, 14, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 31, 32, 
	33, 135, 134, 8, 134, 134, 134, 134, 
	134, 134, 134, 10, 11, 12, 13, 14, 
	134, 134, 134, 134, 134, 134, 21, 22, 
	23, 134, 24, 25, 26, 134, 134, 134, 
	134, 134, 31, 32, 33, 135, 134, 134, 
	134, 134, 11, 134, 8, 134, 134, 134, 
	134, 134, 134, 134, 134, 11, 12, 13, 
	14, 134, 134, 134, 134, 134, 134, 21, 
	22, 23, 134, 24, 25, 26, 134, 134, 
	134, 134, 134, 31, 32, 33, 135, 134, 
	134, 134, 134, 11, 134, 8, 134, 134, 
	134, 134, 134, 134, 134, 134, 11, 12, 
	13, 14, 134, 134, 134, 134, 134, 134, 
	134, 22, 23, 134, 24, 25, 26, 134, 
	134, 134, 134, 134, 31, 32, 33, 135, 
	134, 134, 134, 134, 11, 134, 8, 134, 
	134, 134, 134, 134, 134, 134, 134, 11, 
	12, 13, 14, 134, 134, 134, 134, 134, 
	134, 134, 134, 23, 134, 24, 25, 26, 
	134, 134, 134, 134, 134, 31, 32, 33, 
	135, 134, 134, 134, 134, 11, 134, 137, 
	134, 8, 134, 134, 134, 134, 134, 134, 
	134, 10, 11, 12, 13, 14, 134, 16, 
	17, 134, 134, 134, 21, 22, 23, 134, 
	24, 25, 26, 134, 134, 134, 134, 134, 
	31, 32, 33, 135, 134, 134, 134, 134, 
	11, 134, 8, 134, 134, 134, 134, 134, 
	134, 134, 134, 11, 12, 13, 14, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 24, 25, 26, 134, 134, 134, 134, 
	134, 31, 32, 33, 135, 134, 134, 134, 
	134, 11, 134, 137, 134, 8, 134, 134, 
	134, 134, 134, 134, 134, 10, 11, 12, 
	13, 14, 134, 134, 17, 134, 134, 134, 
	21, 22, 23, 134, 24, 25, 26, 134, 
	134, 134, 134, 134, 31, 32, 33, 135, 
	134, 134, 134, 134, 11, 134, 137, 134, 
	8, 134, 134, 134, 134, 134, 134, 134, 
	10, 11, 12, 13, 14, 134, 134, 134, 
	134, 134, 134, 21, 22, 23, 134, 24, 
	25, 26, 134, 134, 134, 134, 134, 31, 
	32, 33, 135, 134, 134, 134, 134, 11, 
	134, 137, 134, 8, 134, 134, 134, 134, 
	134, 134, 134, 10, 11, 12, 13, 14, 
	15, 16, 17, 134, 134, 134, 21, 22, 
	23, 134, 24, 25, 26, 134, 134, 134, 
	134, 134, 31, 32, 33, 135, 134, 134, 
	134, 134, 11, 134, 5, 6, 134, 8, 
	134, 134, 134, 134, 134, 134, 134, 10, 
	11, 12, 13, 14, 15, 16, 17, 18, 
	134, 20, 21, 22, 23, 134, 24, 25, 
	26, 134, 134, 134, 134, 30, 31, 32, 
	33, 30, 134, 134, 134, 134, 36, 134, 
	5, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 8, 134, 5, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 8, 134, 134, 134, 
	134, 134, 134, 134, 134, 11, 12, 13, 
	14, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 24, 25, 26, 134, 134, 
	134, 134, 134, 31, 32, 33, 135, 134, 
	138, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 8, 134, 7, 8, 134, 1, 
	134, 134, 134, 1, 134, 134, 134, 134, 
	134, 5, 6, 7, 8, 134, 134, 134, 
	134, 134, 134, 134, 10, 11, 12, 13, 
	14, 15, 16, 17, 18, 19, 20, 21, 
	22, 23, 134, 24, 25, 26, 134, 27, 
	28, 134, 30, 31, 32, 33, 30, 134, 
	134, 134, 134, 36, 134, 5, 6, 134, 
	8, 134, 134, 134, 134, 134, 134, 134, 
	10, 11, 12, 13, 14, 15, 16, 17, 
	18, 19, 20, 21, 22, 23, 134, 24, 
	25, 26, 134, 134, 134, 134, 30, 31, 
	32, 33, 30, 134, 134, 134, 134, 36, 
	134, 8, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 27, 28, 134, 8, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 134, 134, 134, 134, 134, 
	134, 134, 134, 28, 134, 1, 139, 139, 
	139, 1, 139, 141, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 142, 
	140, 34, 140, 141, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 34, 142, 
	140, 142, 140, 141, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 140, 140, 
	140, 140, 140, 140, 140, 140, 34, 140, 
	35, 140, 0
};

static const char _use_syllable_machine_trans_targs[] = {
	1, 31, 0, 59, 61, 90, 91, 116, 
	0, 118, 104, 92, 93, 94, 95, 108, 
	110, 111, 112, 119, 113, 105, 106, 107, 
	99, 100, 101, 120, 121, 122, 114, 96, 
	97, 98, 123, 125, 115, 0, 2, 3, 
	0, 16, 4, 5, 6, 7, 20, 22, 
	23, 24, 28, 25, 17, 18, 19, 11, 
	12, 13, 29, 30, 26, 8, 9, 10, 
	27, 14, 15, 21, 0, 32, 33, 0, 
	46, 34, 35, 36, 37, 50, 52, 53, 
	54, 55, 47, 48, 49, 41, 42, 43, 
	56, 38, 39, 40, 57, 58, 44, 0, 
	45, 0, 51, 0, 0, 0, 60, 0, 
	0, 0, 62, 63, 76, 64, 65, 66, 
	67, 80, 82, 83, 84, 89, 85, 77, 
	78, 79, 71, 72, 73, 86, 68, 69, 
	70, 87, 88, 74, 75, 81, 0, 102, 
	103, 109, 117, 0, 0, 0, 124
};

static const char _use_syllable_machine_trans_actions[] = {
	0, 0, 3, 0, 0, 0, 0, 0, 
	4, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 5, 0, 0, 
	6, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 7, 0, 0, 8, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 9, 
	0, 10, 0, 11, 12, 13, 0, 14, 
	15, 16, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 17, 0, 
	0, 0, 0, 18, 19, 20, 0
};

static const char _use_syllable_machine_to_state_actions[] = {
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const char _use_syllable_machine_from_state_actions[] = {
	2, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const short _use_syllable_machine_eof_trans[] = {
	0, 38, 38, 38, 38, 38, 38, 38, 
	38, 38, 38, 38, 38, 38, 38, 38, 
	38, 38, 38, 38, 38, 38, 38, 38, 
	38, 38, 38, 38, 38, 38, 38, 69, 
	69, 69, 69, 69, 69, 69, 69, 69, 
	69, 69, 69, 69, 96, 69, 69, 69, 
	69, 69, 69, 69, 69, 69, 69, 69, 
	100, 96, 69, 102, 105, 69, 69, 69, 
	69, 69, 69, 69, 69, 69, 69, 69, 
	69, 69, 96, 69, 69, 69, 69, 69, 
	69, 69, 69, 69, 69, 69, 100, 96, 
	69, 69, 135, 135, 135, 135, 135, 135, 
	135, 135, 135, 135, 135, 135, 135, 135, 
	135, 135, 135, 135, 135, 135, 135, 135, 
	135, 135, 135, 135, 135, 135, 135, 135, 
	135, 135, 140, 141, 141, 141
};

static const int use_syllable_machine_start = 0;
static const int use_syllable_machine_first_final = 0;
static const int use_syllable_machine_error = -1;

static const int use_syllable_machine_en_main = 0;


#line 58 "hb-ot-shaper-use-machine.rl"



#line 182 "hb-ot-shaper-use-machine.rl"


#define found_syllable(syllable_type) \
  HB_STMT_START { \
    if (0) fprintf (stderr, "syllable %u..%u %s\n", (*ts).second.first, (*te).second.first, #syllable_type); \
    for (unsigned i = (*ts).second.first; i < (*te).second.first; ++i) \
      info[i].syllable() = (syllable_serial << 4) | syllable_type; \
    syllable_serial++; \
    if (syllable_serial == 16) syllable_serial = 1; \
  } HB_STMT_END


template <typename Iter>
struct machine_index_t :
  hb_iter_with_fallback_t<machine_index_t<Iter>,
			  typename Iter::item_t>
{
  machine_index_t (const Iter& it) : it (it) {}
  machine_index_t (const machine_index_t& o) : hb_iter_with_fallback_t<machine_index_t<Iter>,
								       typename Iter::item_t> (),
					       it (o.it), is_null (o.is_null) {}

  static constexpr bool is_random_access_iterator = Iter::is_random_access_iterator;
  static constexpr bool is_sorted_iterator = Iter::is_sorted_iterator;

  typename Iter::item_t __item__ () const { return *it; }
  typename Iter::item_t __item_at__ (unsigned i) const { return it[i]; }
  unsigned __len__ () const { return it.len (); }
  void __next__ () { ++it; }
  void __forward__ (unsigned n) { it += n; }
  void __prev__ () { --it; }
  void __rewind__ (unsigned n) { it -= n; }

  void operator = (unsigned n)
  {
    assert (n == 0);
    is_null = true;
  }
  explicit operator bool () { return !is_null; }

  void operator = (const machine_index_t& o)
  {
    is_null = o.is_null;
    unsigned index = (*it).first;
    unsigned n = (*o.it).first;
    if (index < n) it += n - index; else if (index > n) it -= index - n;
  }
  bool operator == (const machine_index_t& o) const
  { return is_null ? o.is_null : !o.is_null && (*it).first == (*o.it).first; }
  bool operator != (const machine_index_t& o) const { return !(*this == o); }

  private:
  Iter it;
  bool is_null = false;
};
struct
{
  template <typename Iter,
	    hb_requires (hb_is_iterable (Iter))>
  machine_index_t<hb_iter_type<Iter>>
  operator () (Iter&& it) const
  { return machine_index_t<hb_iter_type<Iter>> (hb_iter (it)); }
}
HB_FUNCOBJ (machine_index);



static bool
not_ccs_default_ignorable (const hb_glyph_info_t &i)
{ return i.use_category() != USE(CGJ); }

static inline void
find_syllables_use (hb_buffer_t *buffer)
{
  hb_glyph_info_t *info = buffer->info;
  auto p =
    + hb_iter (info, buffer->len)
    | hb_enumerate
    | hb_filter ([] (const hb_glyph_info_t &i) { return not_ccs_default_ignorable (i); },
		 hb_second)
    | hb_filter ([&] (const hb_pair_t<unsigned, const hb_glyph_info_t &> p)
		 {
		   if (p.second.use_category() == USE(ZWNJ))
		     for (unsigned i = p.first + 1; i < buffer->len; ++i)
		       if (not_ccs_default_ignorable (info[i]))
			 return !_hb_glyph_info_is_unicode_mark (&info[i]);
		   return true;
		 })
    | hb_enumerate
    | machine_index
    ;
  auto pe = p + p.len ();
  auto eof = +pe;
  auto ts = +p;
  auto te = +p;
  unsigned int act HB_UNUSED;
  int cs;
  
#line 933 "hb-ot-shaper-use-machine.hh"
	{
	cs = use_syllable_machine_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 282 "hb-ot-shaper-use-machine.rl"


  unsigned int syllable_serial = 1;
  
#line 946 "hb-ot-shaper-use-machine.hh"
	{
	int _slen;
	int _trans;
	const unsigned char *_keys;
	const unsigned char *_inds;
	if ( p == pe )
		goto _test_eof;
_resume:
	switch ( _use_syllable_machine_from_state_actions[cs] ) {
	case 2:
#line 1 "NONE"
	{ts = p;}
	break;
#line 960 "hb-ot-shaper-use-machine.hh"
	}

	_keys = _use_syllable_machine_trans_keys + (cs<<1);
	_inds = _use_syllable_machine_indicies + _use_syllable_machine_index_offsets[cs];

	_slen = _use_syllable_machine_key_spans[cs];
	_trans = _inds[ _slen > 0 && _keys[0] <=( (*p).second.second.use_category()) &&
		( (*p).second.second.use_category()) <= _keys[1] ?
		( (*p).second.second.use_category()) - _keys[0] : _slen ];

_eof_trans:
	cs = _use_syllable_machine_trans_targs[_trans];

	if ( _use_syllable_machine_trans_actions[_trans] == 0 )
		goto _again;

	switch ( _use_syllable_machine_trans_actions[_trans] ) {
	case 12:
#line 170 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_virama_terminated_cluster); }}
	break;
	case 10:
#line 171 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_sakot_terminated_cluster); }}
	break;
	case 8:
#line 172 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_standard_cluster); }}
	break;
	case 16:
#line 173 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_number_joiner_terminated_cluster); }}
	break;
	case 14:
#line 174 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_numeral_cluster); }}
	break;
	case 6:
#line 175 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_symbol_cluster); }}
	break;
	case 20:
#line 176 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_hieroglyph_cluster); }}
	break;
	case 4:
#line 177 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_broken_cluster); buffer->scratch_flags |= HB_BUFFER_SCRATCH_FLAG_HAS_BROKEN_SYLLABLE; }}
	break;
	case 3:
#line 178 "hb-ot-shaper-use-machine.rl"
	{te = p+1;{ found_syllable (use_non_cluster); }}
	break;
	case 11:
#line 170 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_virama_terminated_cluster); }}
	break;
	case 9:
#line 171 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_sakot_terminated_cluster); }}
	break;
	case 7:
#line 172 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_standard_cluster); }}
	break;
	case 15:
#line 173 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_number_joiner_terminated_cluster); }}
	break;
	case 13:
#line 174 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_numeral_cluster); }}
	break;
	case 5:
#line 175 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_symbol_cluster); }}
	break;
	case 19:
#line 176 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_hieroglyph_cluster); }}
	break;
	case 17:
#line 177 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_broken_cluster); buffer->scratch_flags |= HB_BUFFER_SCRATCH_FLAG_HAS_BROKEN_SYLLABLE; }}
	break;
	case 18:
#line 178 "hb-ot-shaper-use-machine.rl"
	{te = p;p--;{ found_syllable (use_non_cluster); }}
	break;
#line 1050 "hb-ot-shaper-use-machine.hh"
	}

_again:
	switch ( _use_syllable_machine_to_state_actions[cs] ) {
	case 1:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 1059 "hb-ot-shaper-use-machine.hh"
	}

	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _use_syllable_machine_eof_trans[cs] > 0 ) {
		_trans = _use_syllable_machine_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	}

#line 287 "hb-ot-shaper-use-machine.rl"

}

#undef found_syllable

#endif /* HB_OT_SHAPER_USE_MACHINE_HH */
