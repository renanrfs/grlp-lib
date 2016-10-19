#include "Message.h"
#include "Field.h"


/*
 * Default constructor
 */
Field::Field(char *source, const int _length) {
	p_buffer = source;
	length = _length;
	offset = 0;
} 

/*
 * Default constructor
 */
Field::Field(char *source, Field *lastField, const int _length) {
	p_buffer = source;
	offset = lastField->offset + lastField->length;
	length = _length;
}

/**
 * Set buffer with the source content.
 *
 * @source		the source array.
 * @src_offset	starting position in the source array. 
 * @b_offset	starting position in the destination data.
 * @p_length	the number of array elements to be copied.
 */
void Field::set_buffer(const char *source, unsigned char src_offset, unsigned char b_offset, unsigned char p_length) {	
	// copy the source value
	while(p_length) {
		p_buffer[b_offset++] = source[src_offset++];
		p_length--;
	}	
}

/**
 * Set int value in all bytes.
 */
void Field::set_all_bytes(const int _value) {
	memset(&p_buffer[offset], _value, length);
}

/**
 * Set char value.
 */
void Field::set(char *value) {	
	set_all_bytes(' ');
	set_buffer(value, 0, offset, strlen(value));	
}

void Field::set_float(char *value) {	
	set_all_bytes('0');	
	set_buffer(value, 0, offset, strlen(value));	
}

/**
 * Set numeric value.
 */
void Field::set(int value) {
	set_all_bytes('0');
	put(value, length);
}

/**
 * Put in the buffer a int value with a specific size.
 */
void Field::put(int value, int size) {
	int digits = countDigits(value);
	int sizeLeft = size - digits;
	sprintf(&p_buffer[offset + sizeLeft], "%d", value);
}

/**
 * Count digits of value.
 * If is a negative value (-5), then we count 2 digits.
 */
int Field::countDigits(int value) {	
	int result = ((0 > value) ? 1 : 0);	
	while(0 != value) {
		value /= 10;
		result++;
	}
	return result;
}

/**
 * Get the int value.
 */
int Field::get_int() {
	int ofs = offset;
	
	int result = 0;
	int d;
	int s = 1;
	for (int i = length; i-- > 0;) {
	    d = p_buffer[ofs++];
	    if (d < '0' || d > '9') {
			if ('-' == d) {
			    s = -1;
			} else if ((' ' != d) && ('+' != d)) {
				printf("Error!!!!");
			    //throw new NumberFormatException(getName());
			}
	    } else {
			result = (result * 10) + (d - '0');
	    }
	}
	return ((s > 0) ? result : -result);
}

/**
 * Compare buffer values.
 * usege: g001.token.compareTo(&g001.token)
 */
int Field::compareTo(Field *field) {	
	return compareTo(field->get_buffer(), field->get_offset());
}

/**
 * Compare buffer values.
 */
int Field::compareTo(const char *compare_buffer, unsigned char compare_offset) {	
	int lgt = length;
	int ofs = offset;
	while(lgt) {
		if(p_buffer[ofs++] != compare_buffer[compare_offset++]) {
			return 0;
		}		
		lgt--;
	}
	return 1;
}

/**
 * Get the offset
 */
char Field::get_offset() {
	return offset;
}

/**
 * Get the length
 */
char Field::get_length() {
	return length;
}

/**
 * Get the buffer
 */
char * Field::get_buffer() {
	return p_buffer;
}


