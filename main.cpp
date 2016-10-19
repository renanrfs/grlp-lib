
#include "G00101.h"
#include "G10101.h"


void printField(Field field) {
	int lgt = field.get_length();
	printf("\nlength: %d", lgt);
	
	int offset = field.get_offset();
	printf("\noffset: %d", offset);
	
	char *buffer = field.get_buffer();
	printf("\nbuffer: ");	
	while(lgt) {
		printf("%c", buffer[offset++]);
		lgt--;
	}
	printf("\n");
}

float getFloat(Field field) {
	int lgt = field.get_length();
	int ofs = field.get_offset();
		
	float value = 0;
	char char_value[lgt];
	int i = 0;
	while(i < lgt) {
		char_value[i] = field.get_buffer()[ofs++];		
	}
	//sprintf(char_value, "%f", value);
//	value = char_value;
	return value;
}

void getIntTest(G00101 g001) {
	
	printf("\n########### getIntTest::Start ############");
	
	g001.lightSensor.set(1);
	printField(g001.lightSensor);
	g001.trace();
	
	g001.temperatureSensor.set(-22);
	printField(g001.temperatureSensor);
	g001.trace();
	
	g001.humiditySensor.set(333);
	printField(g001.humiditySensor);
	g001.trace();
	
	printf("\nlightSensor: %d", g001.lightSensor.get_int());
	printf("\ntemperatureSensor: %d", g001.temperatureSensor.get_int());
	printf("\nhumiditySensor: %d", g001.humiditySensor.get_int());		
	printField(g001.lightSensor);
	printField(g001.temperatureSensor);
	printField(g001.humiditySensor);
	
	g001.trace();
	
	printf("\n########### getIntTest::End ############\n\n");
}

void compareTest(G00101 g001) {
	
	printf("\n########### compareTest::Start ############\n\n");
	
	printf("\ngrowllerId.compareTo(&g001.growllerId): ");
	if(g001.growllerId.compareTo(&g001.growllerId)){
		printf("true");
	} else {
		printf("false");
	}
	
	printf("\ngrowllerId.compareTo(&g001.transactionDate): ");
	if(g001.growllerId.compareTo(&g001.transactionDate)){
		printf("true");
	} else {
		printf("false");
	}
		
	printf("\ntransactionDate.compareTo(&g001.transactionDate): ");
	if(g001.transactionDate.compareTo(&g001.transactionDate)){
		printf("true");
	} else {
		printf("false");
	}
	
	printf("\n");
	g001.trace();	
	printf("\n########### compareTest::End ############\n\n");
}

void setBufferTest(G00101 g001) {
	
	printf("\n########### setBufferTest::Start ############\n");
	
	g001.growllerId.set(12);
	printField(g001.growllerId);
	g001.trace();
	
	g001.transactionDate.set("20160126114520");
	printField(g001.transactionDate);
	g001.trace();
	
	g001.token.set("token");
	printField(g001.token);
	g001.trace();
	
	g001.ipAddress.set("192.168.123.123");
	printField(g001.ipAddress);
	g001.trace();
	
	g001.lightSensor.set(1);
	printField(g001.lightSensor);
	g001.trace();
	
	g001.temperatureSensor.set(-22);
	printField(g001.temperatureSensor);
	g001.trace();
	
	g001.humiditySensor.set(333);
	printField(g001.humiditySensor);
	g001.trace();
	
	G10101 g101;
	g101.set_buffer("G101010001220151210161520token0   ");
	g101.trace();
	
	printf("\n########### setBufferTest::End ############\n\n");
}

int main() {

	G00101 g001;
	
	int a = 1;
	//while(a) {
						
		setBufferTest(g001);
		
		getIntTest(g001);
		
		compareTest(g001);
		
		g001.ipAddress.set_float("21.352102");
		//float f = getFloat(g001.token);
		//printf("float: %f",f);		
		printField(g001.ipAddress);
		g001.trace();
		
		g001.init();
	//}
	printf("\n########### INIT Test ############");			
	printf("\n");
	g001.transactionDate.set("20160126114520");
	printField(g001.transactionDate);
	g001.trace();
	
	g001.token.set("token");
	printField(g001.token);
	g001.trace();
		
	g001.ipAddress.set("192.168.123.123");
	printField(g001.ipAddress);
	g001.trace();
	
	g001.temperatureSensor.set(123);
	printField(g001.temperatureSensor);
		
	printf("\n########### INIT Test ############");		
	
	
	return 0;
}
