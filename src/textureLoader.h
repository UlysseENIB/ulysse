/*
 * textureLoader.h
 *
 *  Created on: Nov 12, 2014
 *      Author: ifig
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include "Global.h"

struct gl_texture_t
{
  GLsizei width;
  GLsizei height;

  GLenum format;
  GLint internalFormat;
  GLuint id;

  GLubyte *texels;
};

/* File buffer struct */
struct file_buffer_t
{
  char name[256];
  unsigned char *data;
  long length;
  long offset;
};

class TextureLoader {
public:
	TextureLoader();
	virtual ~TextureLoader();

	GLuint init (const char *filename);

	GLuint loadPNGTexture (const struct file_buffer_t *file);

	struct file_buffer_t * readFile (const char *filename);

	void freeFileBuffer (struct file_buffer_t *file);

	void GetPNGtextureInfo (int color_type, struct gl_texture_t *texinfo);

	struct gl_texture_t * ReadPNGFromMemory (const struct file_buffer_t *file);


	static void png_read_from_mem (png_structp png_ptr, png_bytep data, png_size_t length);

	static void png_error_fn (png_structp png_ptr, png_const_charp error_msg);

	static void png_warning_fn (png_structp png_ptr, png_const_charp warning_msg);



};

#endif /* TEXTURELOADER_H_ */
