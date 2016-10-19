#include "Message.h"
#include "Field.h"

class G10101 : public Message {

	public:
	
		G10101() {
			
		}
		
		#include "ResponseHeader.i"
		
		Field turnWater { buffer, &status, 3 };
};
