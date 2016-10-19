#include "Message.h"
#include "Field.h"

class G00101 : public Message {

	public:
	
		G00101() {
			messageCode.set("G001");
			messageVersion.set("01");
		}
		
		#include "RequestHeader.i"
		
		Field ipAddress = add({ buffer, &token, 15 });
		
		Field lightSensor = add({ buffer, &ipAddress, 3 });

		Field temperatureSensor = add({ buffer, &lightSensor, 3 });

		Field humiditySensor = add({ buffer, &temperatureSensor, 3 });
};
