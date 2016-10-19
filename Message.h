#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <string.h>
#include "Field.h"

class Message {

	#define STRING_BUFFER_SIZE 128
	
	protected:		
		char buffer[STRING_BUFFER_SIZE];
		int length;

	public:
		
		/*
		 * Default constructor.
		 */
		Message();

		/*
		 * Initialize message parameters.
		 */
		void init();
		
		/*
		 * Set buffer with the source content.
		 *
		 * @source		the source array.
		 * @src_offset	starting position in the source array. 
		 * @b_offset	starting position in the destination data.
		 * @p_length	the number of array elements to be copied.
		 */
		void set_buffer(const char *source, unsigned char src_offset, unsigned char b_offset, unsigned char p_length);

		/*
		 * Set buffer with the source content.
		 *
		 * @source		the source array.
		 * @b_offset	starting position in the destination data.
		 * @p_length	the number of array elements to be copied.
		 */
		void set_buffer(const char *source, unsigned char b_offset, const unsigned char p_length);

		/*
		 * Set buffer with the source content.
		 *
		 * @source		the source array.
		 * @b_offset	starting position in the destination data.
		 */
		void set_buffer(const char *source, unsigned char b_offset);

		/*
		 * Set buffer with the source content.
		 *
		 * @source		the source array.
		 */
		void set_buffer(const char *source);
		
		/*
		 * Set all bytes of the buffer with the source content.
		 *
		 * @source		the source array.
		 * @b_offset	starting position in the destination data.
		 * @p_length	the number of array elements to be copied.
		 */
		void set_all_bytes(const int source, const unsigned char b_offset, const unsigned char p_length);

		/*
		 * Get length value.
		 */
		int get_length();

		/*
		 * Get buffer value.
		 */
		char * get_buffer();
		
		/*
		 * Print buffer content in ASCII.
		 */
		void traceASCII();

		/*
		 * Print buffer content in HEXADECIMAL.
		 */
		void traceHexadecimal();

		/*
		 * Print buffer content in ASCII and HEXADECIMAL.
		 */
		void trace();
		
		/*
		 * Update Field information in the message.
		 */
		Field add(Field field);	
};
#endif
