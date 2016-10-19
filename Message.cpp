//#include <Arduino.h>
#include "Message.h"

/*
 * Default constructor.
 */
Message::Message() {
	init();
	length = 0;
}

/*
 * Initialize message parameters.
 */
void Message::init() {
	memset(buffer, '\0', STRING_BUFFER_SIZE);	
}

/*
 * Set buffer with the source content.
 *
 * @source		the source array.
 * @src_offset	starting position in the source array. 
 * @b_offset	starting position in the destination data.
 * @p_length	the number of array elements to be copied.
 */
void Message::set_buffer(const char *source, unsigned char src_offset, unsigned char b_offset, unsigned char p_length) {
	// get the source length
	// TODO validate (source length >= STRING_BUFFER_SIZE)
	if(0 >= p_length) {
		p_length = strlen(source);		
	}
	length = length + p_length;
	
	// clean source space
	memset(&buffer[b_offset], '\0', length);
	
	// copy the source value
	while(p_length) {
		buffer[b_offset++] = source[src_offset++];
		p_length--;
	}	
}

/*
 * Set buffer with the source content.
 *
 * @source		the source array.
 * @b_offset	starting position in the destination data.
 * @p_length	the number of array elements to be copied.
 */
void Message::set_buffer(const char *source, unsigned char b_offset, const unsigned char p_length) {
	set_buffer(source, 0, b_offset, p_length);
}

/*
 * Set buffer with the source content.
 *
 * @source		the source array.
 * @b_offset	starting position in the destination data.
 */
void Message::set_buffer(const char *source, unsigned char b_offset) {
	set_buffer(source, 0, b_offset, strlen(source));
}

/*
 * Set buffer with the source content.
 *
 * @source		the source array.
 */
void Message::set_buffer(const char *source) {			
	set_buffer(source, 0, 0, strlen(source));
}

/*
 * Set all bytes of the buffer with the source content.
 *
 * @source		the source array.
 * @b_offset	starting position in the destination data.
 * @p_length	the number of array elements to be copied.
 */
void Message::set_all_bytes(const int source, const unsigned char b_offset, const unsigned char p_length) {	
	memset(&buffer[b_offset], source, p_length);
}

/*
 * Print buffer content in ASCII.
 */
/*
void Message::traceASCII() {
	Serial.print("[T]-LGT=:");
	Serial.print(length);
	Serial.print(":{");
	int offset = 0;
	while(offset < STRING_BUFFER_SIZE) {
		Serial.print((char) buffer[offset++]);
	}
	Serial.print("}\n");
}
*/
void Message::traceASCII() {	
	printf("\n[T]-LGT=:%d:{", length);
	int offset = 0;
	while(offset < STRING_BUFFER_SIZE) {
		printf("%c", buffer[offset++]);
	}
	printf("}");
}

/*
 * Print buffer content in HEXADECIMAL.
 */
/*
void Message::traceHexadecimal() {	
	Serial.print("[T]-LGT=:");
	Serial.print(length);
	Serial.print(":{");
	int offset = 0;
	while(offset < STRING_BUFFER_SIZE) {
		Serial.print(buffer[offset++], HEX);
	}
	Serial.print("}\n");
}
*/
void Message::traceHexadecimal() {	
	printf("\n[T]-LGT=:%d:{", length);
	int offset = 0;
	while(offset < STRING_BUFFER_SIZE) {
		printf("%x.", buffer[offset++]);
	}
	printf("}\n");
}


/*
 * Print buffer content in ASCII and HEXADECIMAL.
 */
void Message::trace() {
	traceASCII();
	traceHexadecimal();
}

/*
 * Get length value.
 */
int Message::get_length() {
	return length;
}

/*
 * Get buffer value.
 */
char * Message::get_buffer() {
	return buffer;
}

/*
 * Update Field information in the message.
 */
Field Message::add(Field field) {
	length += field.get_length();
	return field;
}
