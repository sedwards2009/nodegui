#pragma once

#include <napi.h>

#include <QOpenGLExtraFunctions>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QOpenGLExtraFunctionsWrap
    : public Napi::ObjectWrap<QOpenGLExtraFunctionsWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QOpenGLExtraFunctions* instance;
  bool isOwnsInstance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLExtraFunctionsWrap(const Napi::CallbackInfo& info);
  ~QOpenGLExtraFunctionsWrap();
  QOpenGLExtraFunctions* getInternalInstance();
  // Wrapped methods

  // Open GL Functions

  Napi::Value glActiveTexture(const Napi::CallbackInfo& info);
  Napi::Value glAttachShader(const Napi::CallbackInfo& info);
//void 	 glBindAttribLocation(GLuint program, GLuint index, const char *name)
Napi::Value glBindBuffer(const Napi::CallbackInfo& info);
  Napi::Value glBindFramebuffer(const Napi::CallbackInfo& info);
  Napi::Value glBindRenderbuffer(const Napi::CallbackInfo& info);
  Napi::Value glBindTexture(const Napi::CallbackInfo& info);
  Napi::Value glBlendColor(const Napi::CallbackInfo& info);
  Napi::Value glBlendEquation(const Napi::CallbackInfo& info);
  Napi::Value glBlendEquationSeparate(const Napi::CallbackInfo& info);
  Napi::Value glBlendFunc(const Napi::CallbackInfo& info);
  Napi::Value glBlendFuncSeparate(const Napi::CallbackInfo& info);
Napi::Value glBufferData(const Napi::CallbackInfo& info);
//void 	 glBufferSubData(GLenum target, qopengl_GLintptr offset, qopengl_GLsizeiptr size, const void *data)
  Napi::Value glCheckFramebufferStatus(const Napi::CallbackInfo& info);
Napi::Value glClear(const Napi::CallbackInfo& info);
Napi::Value glClearColor(const Napi::CallbackInfo& info);
  Napi::Value glClearDepthf(const Napi::CallbackInfo& info);
  Napi::Value glClearStencil(const Napi::CallbackInfo& info);
  Napi::Value glColorMask(const Napi::CallbackInfo& info);
  Napi::Value glCompileShader(const Napi::CallbackInfo& info);
//void 	 glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
//void 	 glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
  Napi::Value glCopyTexImage2D(const Napi::CallbackInfo& info);
  Napi::Value glCopyTexSubImage2D(const Napi::CallbackInfo& info);
  Napi::Value glCreateProgram(const Napi::CallbackInfo& info);
  Napi::Value glCreateShader(const Napi::CallbackInfo& info);
Napi::Value glCullFace(const Napi::CallbackInfo& info);
//void 	 glDeleteBuffers(GLsizei n, const GLuint *buffers)
//void 	 glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
  Napi::Value glDeleteProgram(const Napi::CallbackInfo& info);
//void 	 glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
  Napi::Value glDeleteShader(const Napi::CallbackInfo& info);
//void 	 glDeleteTextures(GLsizei n, const GLuint *textures)
Napi::Value glDepthFunc(const Napi::CallbackInfo& info);
  Napi::Value glDepthMask(const Napi::CallbackInfo& info);
  Napi::Value glDepthRangef(const Napi::CallbackInfo& info);
  Napi::Value glDetachShader(const Napi::CallbackInfo& info);
Napi::Value glDisable(const Napi::CallbackInfo& info);
  Napi::Value glDisableVertexAttribArray(const Napi::CallbackInfo& info);
Napi::Value glDrawArrays(const Napi::CallbackInfo& info);
//void 	 glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
Napi::Value glEnable(const Napi::CallbackInfo& info);
Napi::Value glEnableVertexAttribArray(const Napi::CallbackInfo& info);
  Napi::Value glFinish(const Napi::CallbackInfo& info);
  Napi::Value glFlush(const Napi::CallbackInfo& info);
  Napi::Value glFramebufferRenderbuffer(const Napi::CallbackInfo& info);
  Napi::Value glFramebufferTexture2D(const Napi::CallbackInfo& info);
Napi::Value glFrontFace(const Napi::CallbackInfo& info);
Napi::Value glGenBuffer(const Napi::CallbackInfo& info);
  Napi::Value glGenerateMipmap(const Napi::CallbackInfo& info);
//void 	 glGenFramebuffers(GLsizei n, GLuint *framebuffers)
//void 	 glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
//void 	 glGenTextures(GLsizei n, GLuint *textures)
//void 	 glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
//void 	 glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
//void 	 glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders)
//GLint 	 glGetAttribLocation(GLuint program, const char *name)
//void 	 glGetBooleanv(GLenum pname, GLboolean *params)
//void 	 glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
  Napi::Value glGetError(const Napi::CallbackInfo& info);
//void 	 glGetFloatv(GLenum pname, GLfloat *params)
//void 	 glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
//void 	 glGetIntegerv(GLenum pname, GLint *params)
//void 	 glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei *length, char *infolog)
//void 	 glGetProgramiv(GLuint program, GLenum pname, GLint *params)
//void 	 glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
//void 	 glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei *length, char *infolog)
//void 	 glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
//void 	 glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
//void 	 glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, char *source)
Napi::Value glGetString(const Napi::CallbackInfo& info);
//void 	 glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
//void 	 glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
//void 	 glGetUniformfv(GLuint program, GLint location, GLfloat *params)
//void 	 glGetUniformiv(GLuint program, GLint location, GLint *params)
//GLint 	 glGetUniformLocation(GLuint program, const char *name)
//void 	 glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
//void 	 glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
//void 	 glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer)
  Napi::Value glHint(const Napi::CallbackInfo& info);
  Napi::Value glIsBuffer(const Napi::CallbackInfo& info);
  Napi::Value glIsEnabled(const Napi::CallbackInfo& info);
  Napi::Value glIsFramebuffer(const Napi::CallbackInfo& info);
  Napi::Value glIsProgram(const Napi::CallbackInfo& info);
  Napi::Value glIsRenderbuffer(const Napi::CallbackInfo& info);
  Napi::Value glIsShader(const Napi::CallbackInfo& info);
  Napi::Value glIsTexture(const Napi::CallbackInfo& info);
  Napi::Value glLineWidth(const Napi::CallbackInfo& info);
  Napi::Value glLinkProgram(const Napi::CallbackInfo& info);
  Napi::Value glPixelStorei(const Napi::CallbackInfo& info);
  Napi::Value glPolygonOffset(const Napi::CallbackInfo& info);
//void 	 glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
  Napi::Value glReleaseShaderCompiler(const Napi::CallbackInfo& info);
  Napi::Value glRenderbufferStorage(const Napi::CallbackInfo& info);
  Napi::Value glSampleCoverage(const Napi::CallbackInfo& info);
  Napi::Value glScissor(const Napi::CallbackInfo& info);
//void 	 glShaderBinary(GLint n, const GLuint *shaders, GLenum binaryformat, const void *binary, GLint length)
//void 	 glShaderSource(GLuint shader, GLsizei count, const char **string, const GLint *length)
  Napi::Value glStencilFunc(const Napi::CallbackInfo& info);
  Napi::Value glStencilFuncSeparate(const Napi::CallbackInfo& info);
  Napi::Value glStencilMask(const Napi::CallbackInfo& info);
  Napi::Value glStencilMaskSeparate(const Napi::CallbackInfo& info);
  Napi::Value glStencilOp(const Napi::CallbackInfo& info);
  Napi::Value glStencilOpSeparate(const Napi::CallbackInfo& info);
//void 	 glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
  Napi::Value glTexParameterf(const Napi::CallbackInfo& info);
//void 	 glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
  Napi::Value glTexParameteri(const Napi::CallbackInfo& info);
//void 	 glTexParameteriv(GLenum target, GLenum pname, const GLint *params)
//void 	 glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
Napi::Value glUniform1fv(const Napi::CallbackInfo& info);
Napi::Value glUniform1iv(const Napi::CallbackInfo& info);
Napi::Value glUniform2fv(const Napi::CallbackInfo& info);
Napi::Value glUniform2iv(const Napi::CallbackInfo& info);
Napi::Value glUniform3fv(const Napi::CallbackInfo& info);
Napi::Value glUniform3iv(const Napi::CallbackInfo& info);
Napi::Value glUniform4fv(const Napi::CallbackInfo& info);
Napi::Value glUniform4iv(const Napi::CallbackInfo& info);
//void 	 glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
//void 	 glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
//void 	 glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
Napi::Value glUseProgram(const Napi::CallbackInfo& info);
  Napi::Value glValidateProgram(const Napi::CallbackInfo& info);
  Napi::Value glVertexAttrib1f(const Napi::CallbackInfo& info);
//void 	 glVertexAttrib1fv(GLuint indx, const GLfloat *values)
  Napi::Value glVertexAttrib2f(const Napi::CallbackInfo& info);
//void 	 glVertexAttrib2fv(GLuint indx, const GLfloat *values)
  Napi::Value glVertexAttrib3f(const Napi::CallbackInfo& info);
//void 	 glVertexAttrib3fv(GLuint indx, const GLfloat *values)
  Napi::Value glVertexAttrib4f(const Napi::CallbackInfo& info);
//void 	 glVertexAttrib4fv(GLuint indx, const GLfloat *values)
Napi::Value glVertexAttribPointer(const Napi::CallbackInfo& info);
  Napi::Value glViewport(const Napi::CallbackInfo& info);
//bool 	 hasOpenGLFeature(QOpenGLFunctions::OpenGLFeature feature) const
Napi::Value initializeOpenGLFunctions(const Napi::CallbackInfo& info);

  // Extra Open GL Functions

  //void 	glActiveShaderProgram(GLuint pipeline, GLuint program)
  //void 	glBeginQuery(GLenum target, GLuint id)
  //void 	glBeginTransformFeedback(GLenum primitiveMode)
  //void 	glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
  //void 	glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
  //void 	glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
  //void 	glBindProgramPipeline(GLuint pipeline)
  //void 	glBindSampler(GLuint unit, GLuint sampler)
  //void 	glBindTransformFeedback(GLenum target, GLuint id)
  Napi::Value glBindVertexArray(const Napi::CallbackInfo& info);
  //void 	glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
  //void 	glBlendBarrier()
  //void 	glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
  //void 	glBlendEquationi(GLuint buf, GLenum mode)
  //void 	glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
  //void 	glBlendFunci(GLuint buf, GLenum src, GLenum dst)
  //void 	glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
  //void 	glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
  //void 	glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value)
  //void 	glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value)
  //void 	glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value)
  //GLenum 	glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
  //void 	glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
  //void 	glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)
  //void 	glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)
  //void 	glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
  //void 	glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
  //void 	glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
  //GLuint 	glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const *strings)
  //void 	glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam)
  //void 	glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
  //void 	glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)
  //void 	glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines)
  //void 	glDeleteQueries(GLsizei n, const GLuint *ids)
  //void 	glDeleteSamplers(GLsizei count, const GLuint *samplers)
  //void 	glDeleteSync(GLsync sync)
  //void 	glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids)
  //void 	glDeleteVertexArrays(GLsizei n, const GLuint *arrays)
  //void 	glDisablei(GLenum target, GLuint index)
  //void 	glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
  //void 	glDispatchComputeIndirect(GLintptr indirect)
  //void 	glDrawArraysIndirect(GLenum mode, const void *indirect)
  //void 	glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
  //void 	glDrawBuffers(GLsizei n, const GLenum *bufs)
  //void 	glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)
  //void 	glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect)
  //void 	glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount)
  //void 	glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)
  //void 	glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices)
  //void 	glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)
  //void 	glEnablei(GLenum target, GLuint index)
  //void 	glEndQuery(GLenum target)
  //void 	glEndTransformFeedback()
  //GLsync 	glFenceSync(GLenum condition, GLbitfield flags)
  //void 	glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
  //void 	glFramebufferParameteri(GLenum target, GLenum pname, GLint param)
  //void 	glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
  //void 	glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
  //void 	glGenProgramPipelines(GLsizei n, GLuint *pipelines)
  //void 	glGenQueries(GLsizei n, GLuint *ids)
  //void 	glGenSamplers(GLsizei count, GLuint *samplers)
  //void 	glGenTransformFeedbacks(GLsizei n, GLuint *ids)
  Napi::Value glGenVertexArray(const Napi::CallbackInfo& info);
  //void 	glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)
  //void 	glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)
  //void 	glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)
  //void 	glGetBooleani_v(GLenum target, GLuint index, GLboolean *data)
  //void 	glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params)
  //void 	glGetBufferPointerv(GLenum target, GLenum pname, void **params)
  //GLuint 	glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)
  //GLint 	glGetFragDataLocation(GLuint program, const GLchar *name)
  //void 	glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params)
  //GLenum 	glGetGraphicsResetStatus()
  //void 	glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data)
  //void 	glGetInteger64v(GLenum pname, GLint64 *data)
  //void 	glGetIntegeri_v(GLenum target, GLuint index, GLint *data)
  //void 	glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
  //void 	glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val)
  //void 	glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label)
  //void 	glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label)
  //void 	glGetPointerv(GLenum pname, void **params)
  //void 	glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)
  //void 	glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params)
  //void 	glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
  //void 	glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params)
  //GLuint 	glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name)
  //GLint 	glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name)
  //void 	glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name)
  //void 	glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params)
  //void 	glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
  //void 	glGetQueryiv(GLenum target, GLenum pname, GLint *params)
  //void 	glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params)
  //void 	glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params)
  //void 	glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params)
  //void 	glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params)
  //const GLubyte *	glGetStringi(GLenum name, GLuint index)
  //void 	glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)
  //void 	glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params)
  //void 	glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params)
  //void 	glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params)
  //void 	glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params)
  //void 	glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
  //GLuint 	glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName)
  //void 	glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const *uniformNames, GLuint *uniformIndices)
  //void 	glGetUniformuiv(GLuint program, GLint location, GLuint *params)
  //void 	glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params)
  //void 	glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params)
  //void 	glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params)
  //void 	glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params)
  //void 	glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params)
  //void 	glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments)
  //void 	glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)
  //GLboolean 	glIsEnabledi(GLenum target, GLuint index)
  //GLboolean 	glIsProgramPipeline(GLuint pipeline)
  //GLboolean 	glIsQuery(GLuint id)
  //GLboolean 	glIsSampler(GLuint sampler)
  //GLboolean 	glIsSync(GLsync sync)
  //GLboolean 	glIsTransformFeedback(GLuint id)
  //GLboolean 	glIsVertexArray(GLuint array)
  //void *	glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
  //void 	glMemoryBarrier(GLbitfield barriers)
  //void 	glMemoryBarrierByRegion(GLbitfield barriers)
  //void 	glMinSampleShading(GLfloat value)
  //void 	glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label)
  //void 	glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label)
  //void 	glPatchParameteri(GLenum pname, GLint value)
  //void 	glPauseTransformFeedback()
  //void 	glPopDebugGroup()
  //void 	glPrimitiveBoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW)
  //void 	glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)
  //void 	glProgramParameteri(GLuint program, GLenum pname, GLint value)
  //void 	glProgramUniform1f(GLuint program, GLint location, GLfloat v0)
  //void 	glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
  //void 	glProgramUniform1i(GLuint program, GLint location, GLint v0)
  //void 	glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value)
  //void 	glProgramUniform1ui(GLuint program, GLint location, GLuint v0)
  //void 	glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
  //void 	glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1)
  //void 	glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
  //void 	glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1)
  //void 	glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value)
  //void 	glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1)
  //void 	glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
  //void 	glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
  //void 	glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
  //void 	glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
  //void 	glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value)
  //void 	glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
  //void 	glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
  //void 	glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
  //void 	glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
  //void 	glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
  //void 	glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value)
  //void 	glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
  //void 	glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
  //void 	glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message)
  //void 	glReadBuffer(GLenum src)
  //void 	glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data)
  //void 	glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
  //void 	glResumeTransformFeedback()
  //void 	glSampleMaski(GLuint maskNumber, GLbitfield mask)
  //void 	glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param)
  //void 	glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param)
  //void 	glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
  //void 	glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param)
  //void 	glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
  //void 	glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param)
  //void 	glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer)
  //void 	glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
  //void 	glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)
  //void 	glTexParameterIiv(GLenum target, GLenum pname, const GLint *params)
  //void 	glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params)
  //void 	glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
  //void 	glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
  //void 	glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
  //void 	glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
  //void 	glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)
  //void 	glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const *varyings, GLenum bufferMode)
  //void 	glUniform1ui(GLint location, GLuint v0)
  //void 	glUniform1uiv(GLint location, GLsizei count, const GLuint *value)
  //void 	glUniform2ui(GLint location, GLuint v0, GLuint v1)
  //void 	glUniform2uiv(GLint location, GLsizei count, const GLuint *value)
  //void 	glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
  //void 	glUniform3uiv(GLint location, GLsizei count, const GLuint *value)
  //void 	glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
  //void 	glUniform4uiv(GLint location, GLsizei count, const GLuint *value)
  //void 	glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
  //void 	glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //void 	glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  //GLboolean 	glUnmapBuffer(GLenum target)
  //void 	glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
  //void 	glValidateProgramPipeline(GLuint pipeline)
  //void 	glVertexAttribBinding(GLuint attribindex, GLuint bindingindex)
  //void 	glVertexAttribDivisor(GLuint index, GLuint divisor)
  //void 	glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
  //void 	glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
  //void 	glVertexAttribI4iv(GLuint index, const GLint *v)
  //void 	glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
  //void 	glVertexAttribI4uiv(GLuint index, const GLuint *v)
  //void 	glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
  //void 	glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
  //void 	glVertexBindingDivisor(GLuint bindingindex, GLuint divisor)
  //void 	glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)


};
