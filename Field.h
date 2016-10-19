#ifndef FIELD_H
#define FIELD_H

class Field {
	
	private:
		char *p_buffer;
		unsigned char offset;
		unsigned char length;
	
	public:	
		
		/*
		 * Default constructor
		 */
		Field(char *source, const int _length);
	
		/*
		 * Default constructor
		 */ 
		Field(char *source, Field *lastField, const int _length);
		
		/**
		 * Set buffer with the source content.
		 *
		 * @source		the source array.
		 * @src_offset	starting position in the source array. 
		 * @b_offset	starting position in the destination data.
		 * @p_length	the number of array elements to be copied.
		 */
		void set_buffer(const char *source, unsigned char src_offset, unsigned char b_offset, unsigned char p_length);
		
		/**
		 * Set int value in all bytes.
		 */
		void set_all_bytes(const int _value);
		
		/**
		 * Set char value.
		 */
		void set(char *source);
		
		void set_float(char *value);
		
		/**
		 * Set numeric value.
		 */
		void set(int source);
		
		/**
		 * Put in the buffer a int value with a specific size.
		 */		
		void put(int value, int size);
		
		/**
		 * Count digits of value.
		 * If is a negative value (-5), then we count 2 digits.
		 */
		int countDigits(int value);
		int countDigits(float value);
		
		int get_int();
		
		/**
		 * Compare buffer values.
		 * usege: g001.token.compareTo(&g001.token)
		 */
		int compareTo(Field *field);
		
		/**
		 * Compare buffer values.
		 */
		int compareTo(const char *p_buffer, unsigned char p_offset);
		
		/**
		 * Get the offset
		 */
		char get_offset();
		
		/**
		 * Get the length
		 */
		char get_length();
		
		/**
		 * Get the buffer
		 */
		char * get_buffer();
};
#endif
