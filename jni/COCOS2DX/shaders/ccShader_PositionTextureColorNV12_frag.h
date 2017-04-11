/*
 * cocos2d for iPhone: http://www.cocos2d-iphone.org
 *
 * Copyright (c) 2011 Ricardo Quesada
 * Copyright (c) 2012 Zynga Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

"											\n\
#ifdef GL_ES								\n\
precision lowp float;						\n\
#endif										\n\
											\n\
varying vec4 v_fragmentColor;				\n\
varying vec2 v_texCoord;					\n\
uniform sampler2D CC_Texture0;				\n\
uniform sampler2D CC_Texture1;				\n\
											\n\
void main()									\n\
{											\n\
	highp vec3 yuv;											\n\
	yuv.x = texture2D(CC_Texture0, v_texCoord).x;			\n\
	highp vec4 uv = texture2D(CC_Texture1, v_texCoord);		\n\
	yuv.y = uv.r-0.5;										\n\
	yuv.z = uv.a-0.5;										\n\
	highp vec3 rgb = mat3(1,      1,     1,					\n\
	                      0,     -0.34,  1.77,				\n\
	                      1.42,  -0.71,  0) * yuv;			\n\
	gl_FragColor = v_fragmentColor * vec4(rgb, 1);			\n\
}															\n\
";
