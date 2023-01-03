// ----------------------------------------------------------------------------
/// \file		 filter_init.h
/// \brief		 module for different filter class initialization.
/// \license             For educational purposes only. No Warranty. See License.txt
/// \author		 Wolfgang Schulter
/// \date      19.04.2019 ws:  improved version 
/// \date		   25.02.2017 ws:  initial version 
// ----------------------------------------------------------------------------

#ifndef __FILTER_INIT_H__
#define __FILTER_INIT_H__  	  	// only once ..

// -------------------------------------------------------
// Initialization
// -------------------------------------------------------
// TODO: for the SP Bonus Exercise please update your data
// -------------------------------------------------------
/*  0 <= MATR_NR < 10000:    Numbers for examples in the script
 *  MATR_NR >= 10000:        Real Matrikel Numbers of students
 */
// -------------------------------------------------------
//#define MATR_NR 0      // simple IIR1 low-pass
//#define MATR_NR 1      // IIR1 lowpass, bilinear
//#define MATR_NR 252    // FIR comb, 2.5.2
//#define MATR_NR 253    // CIC comb, 2.5.3
//#define MATR_NR 5533   // LP2, 5.5.3.3
//#define MATR_NR 3      // BS2, SP2 sec 5.5.3.3
//#define MATR_NR 4      // BS2, SP2 sec 5.5.3.4
#define MATR_NR 9999   // Butterworth LP6, fg=500 Hz, Script example
//#define MATR_NR 30123  // A. Ch. (Cheby I LP)
//#define MATR_NR 30127  // A. G.  (Cheby I BS)
// -------------------------------------------------------
//#define MATR_NR 31___  // your Matrikel Number (or example nr)
// -------------------------------------------------------
#if (MATR_NR < 10000)
const char init_filter_name[] =  "SP2 example filter"; // 
#else
const char init_filter_name[] =  "SP2 Bonus filter"; // 
#endif
// -------------------------------------------------------

// ----------------------------------------------------------------------------
// TODO: for the Bonus Exercise please enter your filter coeffs
// ----------------------------------------------------------------------------
const double init_b_iir[] = {    // mode 1,2: IIR filter, non-recursive b coeffs
  // ------------------------------------------------------------------------
  // TODO: Determine and Enter the coeffifients of your Bonus Exercise !
  //       !!! Delete or comment-out all other active coeffifients for this array !!!
  // ------------------------------------------------------------------------
  
  // -------------------- other stuff ---------------------------------------
#if (MATR_NR == 0)  
  0.333333333333333          // simple IIR1 low-pass
#endif 

#if (MATR_NR == 1)          // IIR1 lowpass, bilinear
  0.1,  0.1
#endif
  
#if (MATR_NR == 252)  
  1, 0, 0, 0, 0, 1          // FIR comb 2.5.2
#endif

#if (MATR_NR == 253)  
#define CC 0.25
  1, 0, 0, 0, -CC*CC*CC*CC   // CIC c=0.25 2.5.3
#endif

#if ((MATR_NR == 5533) || (MATR_NR == 5534)) 
  0.292893218813453, 0.585786437626905, 0.292893218813453     // LP2, HP2 5.5.3.3 and 5.5.3.4
#endif
  
#if (MATR_NR == 5534)  
  0.074074074074074, 0 , -0.074074074074074                    // BP2, SP2 sec 5.5.3.3
#endif
  
#if (MATR_NR == 5534)  
  0.92592592592592593, -1.111111111111111, 0.92592592592592593  // BS2, SP2 sec 5.5.3.4
#endif

#if (MATR_NR == 9999)  
  0.0003405376527201298,  0.002043225916320779,	0.005108064790801947,  0.006810753054402596,  0.005108064790801947,
    0.002043225916320779,	0.0003405376527201298   // Butterworth LP6, SP2, sec. 5.2.4
  // >> format long; [b,a]=butter(6, 0.2); b 
#endif

#if (MATR_NR == 30123)
  // ------------------------------------------------------------------------
  3.06556868857e-006, 2.145898082e-005, 6.43769424599e-005, 0.0001072949041, 0.0001072949041, 6.43769424599e-005, 
  2.145898082e-005, 3.06556868857e-006  // fprintf('%.12g, ',b);  AENA CHAUHAN, 30123
  // ------------------------------------------------------------------------
#endif

#if (MATR_NR == 30127)
  // ------------------------------------------------------------------------
  0.622188777063, -3.98350645932, 12.0527678503, -22.1559714689, 26.9448749604, 
  -22.1559714689, 12.0527678503, -3.98350645932, 0.622188777063
  // ------------------------------------------------------------------------
#endif
};

const double init_a_iir[] = {    // mode 1,2: IIR filter, recursive a coeffs
  // ------------------------------------------------------------------------
  // TODO: Determine and Enter the coeffifients of your Bonus Exercise!
  //       !!! Delete or comment-out all other active coeffifients for this array !!!
  // ------------------------------------------------------------------------
  
  // -------------------- other stuff ---------------------------------------
#if (MATR_NR == 0)  
  1, -0.666666666666667          // simple IIR1 low-pass
#endif 
  
#if (MATR_NR == 1)  
  1,   -0.8                      // IIR1 lowpass, bilinear
#endif
  
#if (MATR_NR == 252)  
  1                              // FIR comb 2.5.2
#endif  
  
#if (MATR_NR == 253)  
  1, -CC                         // CIC c=0.25 2.5.3
#endif

#if ((MATR_NR == 5533) || (MATR_NTR == 5534))    // LP2, HP2 5.5.3.3 and 5.5.3.4
  1, 0, 0.17157287525381              // LP2, HP2
#endif
  
#if (MATR_NR == 5534)  
  1, -1.111111111111111, 0.851851851851852    // BP2, BS2 , SP2 sec 5.5.3.3/4
#endif

#if (MATR_NR == 9999)  
  1,  -3.579434798331188,  5.658667165933613,  -4.965415228778555,  2.529494905841437,
    -0.7052741145098973, 	0.08375647961867848   // Butterworth LP6, SP2, sec. 5.2.4 
  // >> format long; [b,a]=butter(6, 0.2); a 
#endif  

#if (MATR_NR == 30123)  
  // ------------------------------------------------------------------------
  1, -5.93717036749, 15.5410828296, -23.203288828, 21.3129770484, -12.0339743517, 
  3.86573325707, -0.544967195179   // fprintf('%.12g, ',a);  AENA CHAUHAN, 30123
  // ------------------------------------------------------------------------
#endif

#if (MATR_NR == 30127)  
  // ------------------------------------------------------------------------
  1, -5.80645908066, 15.9631463259, -26.7632468389, 29.8178539257, 
  -22.5793061603, 11.3796739393, -3.50894116261, 0.515043250229
  // ------------------------------------------------------------------------
#endif

};

const double init_b_fir[] = {      // ------- mode 3,4: FIR filter, b coeffs
  // ------------------------------------------------------------------------
  // TODO: Determine and Enter the coeffifients of your Bonus Exercise!
  //       !!! Delete or comment-out all other active coeffifients for this array !!!
  // ------------------------------------------------------------------------
  
  // -------------------- other stuff ---------------------------------------
#if (MATR_NR == 0)  
  // g=filter([1/3],[1 -2/3],[1 zeros(1,25)])
  // fprintf('%.12f ',g(1:25));  25 because (2^13*g[24]) < 1 !!
  0.333333333333, 0.222222222222, 0.148148148148, 0.098765432099, 0.065843621399, 
  0.043895747599, 0.029263831733, 0.019509221155, 0.013006147437, 0.008670764958, 
  0.005780509972, 0.003853673315, 0.002569115543, 0.001712743695, 0.001141829130, 
  0.000761219420, 0.000507479613, 0.000338319742, 0.000225546495, 0.000150364330, 
  0.000100242887, 0.000066828591, 0.000044552394, 0.000029701596, 0.000019801064
#endif  
  
#if (MATR_NR == 1)  
  // g=filter([.1 .1],[1 -.8],[1 zeros(1,50)])
  // fprintf('%.12f ',g(1:37));  37 because (2^13*g[36]) < 1 !!
  0.100000000000, 0.180000000000, 0.144000000000, 0.115200000000, 0.092160000000, 
  0.073728000000, 0.058982400000, 0.047185920000, 0.037748736000, 0.030198988800, 
  0.024159191040, 0.019327352832, 0.015461882266, 0.012369505812, 0.009895604650, 
  0.007916483720, 0.006333186976, 0.005066549581, 0.004053239665, 0.003242591732, 
  0.002594073385, 0.002075258708, 0.001660206967, 0.001328165573, 0.001062532459, 
  0.000850025967, 0.000680020774, 0.000544016619, 0.000435213295, 0.000348170636, 
  0.000278536509, 0.000222829207, 0.000178263366, 0.000142610693, 0.000114088554, 
  0.000091270843, 0.000073016675
#endif

#if (MATR_NR == 2)  
   1, 1
#endif

#if (MATR_NR == 3)  
   1, 1
#endif
  // 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
  
#if (MATR_NR == 9999)  
  // ------------------------------------------------------------------------
  0.000340537653, 0.00326215824, 0.0148577583, 0.0432245732, 0.0910890792, 0.149260672, 0.198484122, 0.219008839, 0.200744867, 0.147879439,
  0.0764220591, 0.00703129504, -0.0429423021, -0.0648532109, -0.0600556976, -0.0374820659, -0.00917204546, 0.0142371773, 0.0265165658, 0.0266946991,
  0.0179925765, 0.00567028942, -0.00523149287, -0.0114865683, -0.0122627886, -0.00876084335, -0.00327826164, 0.00184119175, 0.00499544569, 0.00565820634,
  0.00426853583, 0.00182992051, -0.000571632353, -0.00214943634, -0.00259782897, -0.00206640476, -0.000990136417, 0.00013023158, 0.000911581459, 0.0011843788,
  0.000992472727, 0.000522203541, 2.99186433e-006, -0.000380100729, -0.000536012175, -0.000473046541, -0.000269879991, -3.08929056e-005, 0.000155223678, 0.000240728687,
  0.000223844485
  // ------------------------------------------------------------------------
#endif  

#if (MATR_NR == 30123) // AENA CHAUHAN, 30123
  // ------------------------------------------------------------------------
  0.0000030656, 0.0000396598, 0.0002522016, 0.0010594339, 0.0033327501, 0.0084302604, 0.0179514054, 0.0332026580, 0.0545203705, 0.0806973482, 
  0.1087646559, 0.1342883877, 0.1521837883, 0.1578781654, 0.1485253051, 0.1239299354, 0.0868974286, 0.0428671717, -0.0011221388, -0.0379043210, 
  -0.0617398204, -0.0695672241, -0.0616396741, -0.0413888086, -0.0145546815, 0.0121958196, 0.0328155222, 0.0432092514, 0.0420374773, 0.0308197562,
  0.0133476483, -0.0054116339, -0.0206214964, -0.0287562367, -0.0283700134, -0.0202897083, -0.0072226670, 0.0070806343, 0.0188647078, 0.0253286069,
  0.0252666755, 0.0192489310, 0.0093284337, -0.0016133304, -0.0106855555, -0.0157452125, -0.0158979958, -0.0116302070, -0.0045641415, 0.0030701837, 
  0.0090852826, 0.0119255752, 0.0110420178, 0.0069662998, 0.0010855271, -0.0048010262, -0.0090080472, -0.0104245058, -0.0087868458, -0.0047021674, 
  0.0005696352, 0.0055007802, 0.0087324863, 0.0094413656, 0.0075390999, 0.0036600320, -0.0010484251, -0.0052648366, -0.0078630190, -0.0082094595, 
  -0.0063117755, -0.0027856244, 0.0013416061, 0.0049287607, 0.0070347067, 0.0071623446, 0.0053705606, 0.0022307340, -0.0013524569, -0.0044006685, 
  -0.0061279599, -0.0061414585, -0.0045261698, -0.0017972765, 0.0012602579, 0.0038157824, 0.0052172883, 0.0051558732, 0.0037295327, 0.0013946727, 
  -0.0011755485, -0.0032830224, -0.0043925405, -0.0042656366, -0.0030075938, -0.0010198724, 0.0011240276, 0.0028417448, 0.0036983895, 0.0035145483, 
  0.0023997497, 0.0007066295, -0.0010774457, -0.0024687109, -0.0031165135, -0.0028897712, -0.0018996235, -0.0004558095, 0.0010277767, 0.0021501348, 
  0.0026301167, 0.0023751526, 0.0014954480, 0.0002629147, -0.0009710222, -0.0018743500, -0.0022226135, -0.0019532061, -0.0011731216, -0.0001206931 
  // ------------------------------------------------------------------------
#endif

#if (MATR_NR == 30127)  // Ashreeth Gopalkrishna, 30127
  // ------------------------------------------------------------------------
  0.62218878, -0.37079278, -0.032315773, 0.22719962, 0.30400877, 0.22238323, 0.08272772, -0.018373524, -0.042074454, -0.011502826, 
  0.021964157, 0.019982479, -0.020396549, -0.071770782, -0.099281229, -0.08383723, -0.032041481, 0.03028243, 0.074289717, 0.083434256, 
  0.0598915, 0.020320268, -0.014924238, -0.032417623, -0.030736605, -0.01837604, -0.0068636283, -0.0035348052, -0.0079410738, -0.013385122, 
  -0.012110438, -0.00079779433, 0.016887428, 0.032093822, 0.035802383, 0.024146483, 0.00099646457, -0.023664614, -0.0387055, -0.037464226, 
  -0.02101834, 0.0025670968, 0.022493978, 0.030627541, 0.025177315, 0.010869818, -0.004203361, -0.013114704, -0.013465389, -0.0078817529, 
  -0.0016637823, 0.00079893109, -0.0013480145, -0.0052377747, -0.0064885459, -0.0023336592, 0.0062936143, 0.015013323, 0.018461549, 0.013514327, 
  0.0013695645, -0.012761478, -0.022233695, -0.022411845, -0.013092682, 0.0013986118, 0.014450678, 0.020496782, 0.017646127, 0.008283662, 
  -0.0025371507, -0.0098953906, -0.011418182, -0.0080641974, -0.0030232791, 0.00045713483, 0.00097620293, -0.00046218704, -0.0014492347, 
  -6.1618435e-006, 0.0039304456, 0.0083003742, 0.010118109, 0.0073523337, 0.00034979575, -0.0080715786, -0.01396481, -0.014308241, -0.0086387399, 
  0.00063734401, 0.0094242844, 0.013964881, 0.012633332, 0.0065735842, -0.0010823223, -0.0069157769, -0.008889532, -0.007118698, -0.0034338414, 
  -0.00010698701 
  // ------------------------------------------------------------------------
#endif
};

const double init_sos[] = {    // ------- mode 5,6: SOS IIR filter, [b0,b1,b2,a0,a1,a2] each section
  // ------------------------------------------------------------------------
  // TODO: Determine and Enter the coeffifients of your Bonus Exercise!
  //       !!! Delete or comment-out all other active coeffifients for this array !!!
  // ------------------------------------------------------------------------
  
  // -------------------- other stuff ---------------------------------------
#if (MATR_NR == 0)  // simple IIR1 low-pass
  // format long; b=1/3; a=[1 -2/3];sos g]=tf2sos(b,a); [sos(:,1:3)*g sos(:,4:6)]
  0.333333333333333,      0,            0, 1, -0.666666666666667,     0
  // ------------------------------------------------------------------------
#endif

#if (MATR_NR == 1)  // simple IIR1 low-pass
  // format long; b=[.1 .1]; a=[1 -.8];sos g]=tf2sos(b,a); [sos(:,1:3)*g sos(:,4:6)]
  0.1,                  0.1,            0, 1, -0.8,                   0
  // ------------------------------------------------------------------------
#endif

#if (MATR_NR == 9999)  
  // --- Butterworth LP 6. order, fg = 500 Hz
  // format long; [b,a]=butter(6, 0.2); [sos g]=tf2sos(b,a); [sos(:,1:3)*g^(1/3) sos(:,4:6)]
  0.0698320909, 0.139322752, 0.0694923271, 1, -1.40438489, 0.735915191,
  0.0698320909, 0.140005175, 0.0701747523, 1, -1.1429805, 0.412801598,
  0.0698320909, 0.139664619, 0.0698308606, 1, -1.03206941, 0.275707942
  // ------------------------------------------------------------------------
#endif

#if (MATR_NR == 30123) // AENA CHAUHAN, 30123
  // ------------------------------------------------------------------------
  0.0145268, 0.0146572, 0, 1, -0.87053, 0,
  0.0145268, 0.0292171, 0.0146915, 1, -1.71696, 0.781812,
  0.0145268, 0.0289962, 0.0144706, 1, -1.67397, 0.848008,
  0.0145268, 0.0288171, 0.0142915, 1, -1.67571, 0.944245
  // ------------------------------------------------------------------------
#endif

#if (MATR_NR == 30127)  // Ashreeth Gopalkrishna, 30127
  // ------------------------------------------------------------------------
  0.853704, -1.3666, 0.854164, 1, -1.11157, 0.69129,
  0.853704, -1.36699, 0.85405, 1, -1.59729, 0.799361,
  0.853704, -1.36589, 0.853359, 1, -1.39505, 0.959854,
  0.853704, -1.36628, 0.853245, 1, -1.70254, 0.971036
  // ------------------------------------------------------------------------
#endif

};

#endif // #ifndef __FILTER_INIT_H__