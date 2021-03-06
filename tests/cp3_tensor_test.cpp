#include "cp3_tensor_test.hpp"
#include <vmmlib/cp3_tensor.hpp>
#include <vmmlib/t3_hopm.hpp>
#include <sstream>

namespace vmml
{
	
	bool
	cp3_tensor_test::run()
	{
		bool ok = false;
		
		typedef tensor3< 4,4,4, float > t3_type;
		typedef cp3_tensor< 3, 4, 4, 4, float, float > cp3_dec_type;
		typedef t3_hopm< 3, 4, 4, 4, float > t3_hopm_type;
		
		t3_type t3_cp_input;
		float data_in_cp[] = { 
		/*	0.3780, 0.3150, 0.3386, 0.2047, 0.2913, 0.3071, 0.2835, 0.1024, 0.2362, 0.2835, 0.2677, 0.1024, 0.3543, 1.1181, 1.5354, 0.3858, 
			0.2520, 0.2283, 0.3228, 0.2835, 0.2677, 0.2598, 0.2992, 0.2126, 0.2441, 0.2205, 0.2441, 0.2913, 0.9213, 0.6457, 0.4331, 0.1890,
			0.4409, 0.4409, 0.5591, 0.5039, 0.2362, 0.4409, 0.5984, 0.6142, 0.2520, 0.2835, 0.3465, 0.3543, 0.5748, 0.2835, 0.2992, 0.2835,
			0.3386, 0.3150, 0.4488, 0.4173, 0.2756, 0.3150, 0.3465, 0.3386, 0.2835, 0.2677, 0.2362, 0.2913, 0.2598, 0.2520, 0.2756, 0.3071 */
		
			0.8147, 0.6324, 0.9575, 0.9572,
			0.9058, 0.0975, 0.9649, 0.4854,
			0.1270, 0.2785, 0.1576, 0.8003,
			0.9134, 0.5469, 0.9706, 0.1419,

			0.4218, 0.6557, 0.6787, 0.6555,
			0.9157, 0.0357, 0.7577, 0.1712,
			0.7922, 0.8491, 0.7431, 0.7060,
			0.9595, 0.9340, 0.3922, 0.0318,
			0.2769, 0.6948, 0.4387, 0.1869,
			0.0462, 0.3171, 0.3816, 0.4898,
			0.0971, 0.9502, 0.7655, 0.4456,
			0.8235, 0.0344, 0.7952, 0.6463,
			0.7094, 0.6551, 0.9597, 0.7513,
			0.7547, 0.1626, 0.3404, 0.2551,
			0.2760, 0.1190, 0.5853, 0.5060,
			0.6797, 0.4984, 0.2238, 0.6991
		
		};
		t3_cp_input.set(data_in_cp, data_in_cp + 64);
		
		cp3_dec_type cp3_dec;
		cp3_dec.decompose( t3_cp_input, t3_hopm_type::init_hosvd() );
		
		t3_type t3_cp_reco;
		cp3_dec.reconstruct( t3_cp_reco );
		
		
		t3_type t3_cp_reco_check;
		float data_out_cp[] = { 
			0.658735, 0.555868, 0.788278, 0.785259,
			1.0863, 0.0696195, 0.878343, 0.328856,
			0.204135, 0.525463, 0.463267, 0.777254,
			1.02116, 0.651616, 0.848481, 0.161661,
			0.744683, 0.569311, 0.851989, 0.790796,
			0.858943, 0.169862, 0.734341, 0.338445,
			0.441856, 0.487661, 0.623644, 0.772226,
			0.706845, 0.750421, 0.656499, 0.211157,
			0.371909, 0.81205, 0.513955, 0.468264,
			0.144107, 0.359317, 0.24075, 0.291169,
			0.254145, 0.824074, 0.388849, 0.334694,
			0.813514, -0.0044108, 0.792204, 0.67506,
			0.632346, 0.555974, 0.726074, 0.652605,
			0.559222, 0.221787, 0.517159, 0.297763,
			0.449981, 0.480387, 0.575679, 0.612093,
			0.534163, 0.575728, 0.539401, 0.287718	
		};
		t3_cp_reco_check.set(data_out_cp, data_out_cp + 64);
				
		ok = t3_cp_reco.equals( t3_cp_reco_check, 0.0001 );
		
		log( "cp3 tensor reconstruction ", ok  );
		
		return ok;
	}
	
	
} // namespace vmml

