#include "QtGui/QOpenGLExtraFunctions/qopenglextrafunctions_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtGui/QOpenGLContext/qopenglcontext_wrap.h"

Napi::FunctionReference QOpenGLExtraFunctionsWrap::constructor;

Napi::Object QOpenGLExtraFunctionsWrap::init(Napi::Env env,
                                             Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLExtraFunctions";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("glBindBuffer", &QOpenGLExtraFunctionsWrap::glBindBuffer),
       InstanceMethod("glBindVertexArray",
                      &QOpenGLExtraFunctionsWrap::glBindVertexArray),
       InstanceMethod("glBufferData", &QOpenGLExtraFunctionsWrap::glBufferData),
       InstanceMethod("glClear", &QOpenGLExtraFunctionsWrap::glClear),
       InstanceMethod("glClearColor", &QOpenGLExtraFunctionsWrap::glClearColor),
       InstanceMethod("glCullFace", &QOpenGLExtraFunctionsWrap::glCullFace),
       InstanceMethod("glDepthFunc", &QOpenGLExtraFunctionsWrap::glDepthFunc),
       InstanceMethod("glDisable", &QOpenGLExtraFunctionsWrap::glDisable),
       InstanceMethod("glDrawArrays", &QOpenGLExtraFunctionsWrap::glDrawArrays),
       InstanceMethod("glEnable", &QOpenGLExtraFunctionsWrap::glEnable),
       InstanceMethod("glEnableVertexAttribArray",
                      &QOpenGLExtraFunctionsWrap::glEnableVertexAttribArray),
       InstanceMethod("glFrontFace", &QOpenGLExtraFunctionsWrap::glFrontFace),
       InstanceMethod("glGenBuffer", &QOpenGLExtraFunctionsWrap::glGenBuffer),
       InstanceMethod("glGenVertexArray",
                      &QOpenGLExtraFunctionsWrap::glGenVertexArray),
       InstanceMethod("glGetString", &QOpenGLExtraFunctionsWrap::glGetString),
       InstanceMethod("glUniform1fv", &QOpenGLExtraFunctionsWrap::glUniform1fv),
       InstanceMethod("glUniform2fv", &QOpenGLExtraFunctionsWrap::glUniform2fv),
       InstanceMethod("glUniform3fv", &QOpenGLExtraFunctionsWrap::glUniform3fv),
       InstanceMethod("glUniform4fv", &QOpenGLExtraFunctionsWrap::glUniform4fv),
       InstanceMethod("glUniform1iv", &QOpenGLExtraFunctionsWrap::glUniform1iv),
       InstanceMethod("glUniform2iv", &QOpenGLExtraFunctionsWrap::glUniform2iv),
       InstanceMethod("glUniform3iv", &QOpenGLExtraFunctionsWrap::glUniform3iv),
       InstanceMethod("glUniform4iv", &QOpenGLExtraFunctionsWrap::glUniform4iv),
       InstanceMethod("glUseProgram", &QOpenGLExtraFunctionsWrap::glUseProgram),
       InstanceMethod("glVertexAttribPointer",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribPointer),
       InstanceMethod("initializeOpenGLFunctions",
                      &QOpenGLExtraFunctionsWrap::initializeOpenGLFunctions),

       InstanceMethod("glActiveTexture", &QOpenGLExtraFunctionsWrap::glActiveTexture),
       InstanceMethod("glAttachShader", &QOpenGLExtraFunctionsWrap::glAttachShader),
       InstanceMethod("glBindFramebuffer", &QOpenGLExtraFunctionsWrap::glBindFramebuffer),
       InstanceMethod("glBindRenderbuffer", &QOpenGLExtraFunctionsWrap::glBindRenderbuffer),
       InstanceMethod("glBindTexture", &QOpenGLExtraFunctionsWrap::glBindTexture),
       InstanceMethod("glBlendColor", &QOpenGLExtraFunctionsWrap::glBlendColor),
       InstanceMethod("glBlendEquation", &QOpenGLExtraFunctionsWrap::glBlendEquation),
       InstanceMethod("glBlendEquationSeparate", &QOpenGLExtraFunctionsWrap::glBlendEquationSeparate),
       InstanceMethod("glBlendFunc", &QOpenGLExtraFunctionsWrap::glBlendFunc),
       InstanceMethod("glBlendFuncSeparate", &QOpenGLExtraFunctionsWrap::glBlendFuncSeparate),
       InstanceMethod("glCheckFramebufferStatus", &QOpenGLExtraFunctionsWrap::glCheckFramebufferStatus),
       InstanceMethod("glClearDepthf", &QOpenGLExtraFunctionsWrap::glClearDepthf),
       InstanceMethod("glClearStencil", &QOpenGLExtraFunctionsWrap::glClearStencil),
       InstanceMethod("glColorMask", &QOpenGLExtraFunctionsWrap::glColorMask),
       InstanceMethod("glCompileShader", &QOpenGLExtraFunctionsWrap::glCompileShader),
       InstanceMethod("glCopyTexImage2D", &QOpenGLExtraFunctionsWrap::glCopyTexImage2D),
       InstanceMethod("glCopyTexSubImage2D", &QOpenGLExtraFunctionsWrap::glCopyTexSubImage2D),
       InstanceMethod("glCreateProgram", &QOpenGLExtraFunctionsWrap::glCreateProgram),
       InstanceMethod("glCreateShader", &QOpenGLExtraFunctionsWrap::glCreateShader),
       InstanceMethod("glDeleteProgram", &QOpenGLExtraFunctionsWrap::glDeleteProgram),
       InstanceMethod("glDeleteShader", &QOpenGLExtraFunctionsWrap::glDeleteShader),
       InstanceMethod("glDepthMask", &QOpenGLExtraFunctionsWrap::glDepthMask),
       InstanceMethod("glDepthRangef", &QOpenGLExtraFunctionsWrap::glDepthRangef),
       InstanceMethod("glDetachShader", &QOpenGLExtraFunctionsWrap::glDetachShader),
       InstanceMethod("glDisableVertexAttribArray", &QOpenGLExtraFunctionsWrap::glDisableVertexAttribArray),
       InstanceMethod("glFinish", &QOpenGLExtraFunctionsWrap::glFinish),
       InstanceMethod("glFlush", &QOpenGLExtraFunctionsWrap::glFlush),
       InstanceMethod("glFramebufferRenderbuffer", &QOpenGLExtraFunctionsWrap::glFramebufferRenderbuffer),
       InstanceMethod("glFramebufferTexture2D", &QOpenGLExtraFunctionsWrap::glFramebufferTexture2D),
       InstanceMethod("glGenerateMipmap", &QOpenGLExtraFunctionsWrap::glGenerateMipmap),
       InstanceMethod("glGetError", &QOpenGLExtraFunctionsWrap::glGetError),
       InstanceMethod("glHint", &QOpenGLExtraFunctionsWrap::glHint),
       InstanceMethod("glIsBuffer", &QOpenGLExtraFunctionsWrap::glIsBuffer),
       InstanceMethod("glIsEnabled", &QOpenGLExtraFunctionsWrap::glIsEnabled),
       InstanceMethod("glIsFramebuffer", &QOpenGLExtraFunctionsWrap::glIsFramebuffer),
       InstanceMethod("glIsProgram", &QOpenGLExtraFunctionsWrap::glIsProgram),
       InstanceMethod("glIsRenderbuffer", &QOpenGLExtraFunctionsWrap::glIsRenderbuffer),
       InstanceMethod("glIsShader", &QOpenGLExtraFunctionsWrap::glIsShader),
       InstanceMethod("glIsTexture", &QOpenGLExtraFunctionsWrap::glIsTexture),
       InstanceMethod("glLineWidth", &QOpenGLExtraFunctionsWrap::glLineWidth),
       InstanceMethod("glLinkProgram", &QOpenGLExtraFunctionsWrap::glLinkProgram),
       InstanceMethod("glPixelStorei", &QOpenGLExtraFunctionsWrap::glPixelStorei),
       InstanceMethod("glPolygonOffset", &QOpenGLExtraFunctionsWrap::glPolygonOffset),
       InstanceMethod("glReleaseShaderCompiler", &QOpenGLExtraFunctionsWrap::glReleaseShaderCompiler),
       InstanceMethod("glRenderbufferStorage", &QOpenGLExtraFunctionsWrap::glRenderbufferStorage),
       InstanceMethod("glSampleCoverage", &QOpenGLExtraFunctionsWrap::glSampleCoverage),
       InstanceMethod("glScissor", &QOpenGLExtraFunctionsWrap::glScissor),
       InstanceMethod("glStencilFunc", &QOpenGLExtraFunctionsWrap::glStencilFunc),
       InstanceMethod("glStencilFuncSeparate", &QOpenGLExtraFunctionsWrap::glStencilFuncSeparate),
       InstanceMethod("glStencilMask", &QOpenGLExtraFunctionsWrap::glStencilMask),
       InstanceMethod("glStencilMaskSeparate", &QOpenGLExtraFunctionsWrap::glStencilMaskSeparate),
       InstanceMethod("glStencilOp", &QOpenGLExtraFunctionsWrap::glStencilOp),
       InstanceMethod("glStencilOpSeparate", &QOpenGLExtraFunctionsWrap::glStencilOpSeparate),
       InstanceMethod("glTexParameterf", &QOpenGLExtraFunctionsWrap::glTexParameterf),
       InstanceMethod("glTexParameteri", &QOpenGLExtraFunctionsWrap::glTexParameteri),
       InstanceMethod("glValidateProgram", &QOpenGLExtraFunctionsWrap::glValidateProgram),
       InstanceMethod("glVertexAttrib1f", &QOpenGLExtraFunctionsWrap::glVertexAttrib1f),
       InstanceMethod("glVertexAttrib2f", &QOpenGLExtraFunctionsWrap::glVertexAttrib2f),
       InstanceMethod("glVertexAttrib3f", &QOpenGLExtraFunctionsWrap::glVertexAttrib3f),
       InstanceMethod("glVertexAttrib4f", &QOpenGLExtraFunctionsWrap::glVertexAttrib4f),
       InstanceMethod("glViewport", &QOpenGLExtraFunctionsWrap::glViewport),

       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLExtraFunctionsWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLExtraFunctions* QOpenGLExtraFunctionsWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLExtraFunctionsWrap::QOpenGLExtraFunctionsWrap(
    const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLExtraFunctionsWrap>(info), isOwnsInstance(true) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 0) {
    this->instance = new QOpenGLExtraFunctions();
  } else if (info.Length() == 1) {
    if (info[0].IsExternal()) {
      this->instance =
          info[0].As<Napi::External<QOpenGLExtraFunctions>>().Data();
      this->isOwnsInstance = false;
    } else {
      Napi::Object contextObject = info[0].As<Napi::Object>();
      QOpenGLContextWrap* contextWrap =
          Napi::ObjectWrap<QOpenGLContextWrap>::Unwrap(contextObject);
      QOpenGLContext* context = contextWrap->getInternalInstance();
      this->instance = new QOpenGLExtraFunctions(context);
    }
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLExtraFunctionsWrap::~QOpenGLExtraFunctionsWrap() {
  if (this->isOwnsInstance) {
    delete this->instance;
  }
}

Napi::Value QOpenGLExtraFunctionsWrap::initializeOpenGLFunctions(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->initializeOpenGLFunctions();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint bufferId = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindBuffer(target, bufferId);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glClearColor(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto red = info[0].As<Napi::Number>().FloatValue();
  auto green = info[1].As<Napi::Number>().FloatValue();
  auto blue = info[2].As<Napi::Number>().FloatValue();
  auto alpha = info[3].As<Napi::Number>().FloatValue();
  this->instance->glClearColor(red, green, blue, alpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glClear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glClear(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFrontFace(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glFrontFace(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCullFace(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glCullFace(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDisable(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glDisable(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glEnable(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glEnable(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDrawArrays(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum mode = info[0].As<Napi::Number>().Int32Value();
  GLint first = info[1].As<Napi::Number>().Int32Value();
  GLint count = info[2].As<Napi::Number>().Int32Value();
  this->instance->glDrawArrays(mode, first, count);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUseProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint programId = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glUseProgram(programId);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGetString(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum name = info[0].As<Napi::Number>().Uint32Value();
  QString result((const char*)(this->instance->glGetString(name)));
  return Napi::String::New(env, result.toStdString());
}

Napi::Value QOpenGLExtraFunctionsWrap::glDepthFunc(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum func = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDepthFunc(func);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGenVertexArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLuint result = 0;
  this->instance->glGenVertexArrays(1, &result);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindVertexArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint vertextArrayFunc = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glBindVertexArray(vertextArrayFunc);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glEnableVertexAttribArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glEnableVertexAttribArray(index);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribPointer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 6) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  GLint size = info[1].As<Napi::Number>().Uint32Value();
  GLenum type = info[2].As<Napi::Number>().Uint32Value();
  GLboolean normalized = info[3].As<Napi::Boolean>().ToBoolean();
  GLsizei stride = info[4].As<Napi::Number>().Uint32Value();
  uint pointer_offset = info[5].As<Napi::Number>().Uint32Value();
  this->instance->glVertexAttribPointer(index, size, type, normalized, stride,
                                        reinterpret_cast<void *>(pointer_offset));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGenBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLuint result = 0;
  this->instance->glGenBuffers(1, &result);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glBufferData(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLint size = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  GLenum usage = info[3].As<Napi::Number>().Int32Value();
  this->instance->glBufferData(target, size, data.Data(), usage);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform1fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[1].As<Napi::ArrayBuffer>();
  this->instance->glUniform1fv(location, count, static_cast<const GLfloat *>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform2fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform2fv(location, count, static_cast<const GLfloat *>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform3fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform3fv(location, count, static_cast<const GLfloat *>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform4fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform4fv(location, count, static_cast<const GLfloat *>(data.Data()));
  return env.Null();
}
//---
Napi::Value QOpenGLExtraFunctionsWrap::glUniform1iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[1].As<Napi::ArrayBuffer>();
  this->instance->glUniform1iv(location, count, static_cast<const GLint *>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform2iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform2iv(location, count, static_cast<const GLint *>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform3iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform3iv(location, count, static_cast<const GLint *>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform4iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform4iv(location, count, static_cast<const GLint *>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glActiveTexture(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum texture = info[0].As<Napi::Number>().Int32Value();
  this->instance->glActiveTexture(texture);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glAttachShader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLuint shader = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glAttachShader(program, shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindFramebuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint framebuffer = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindFramebuffer(target, framebuffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindRenderbuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint renderbuffer = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindRenderbuffer(target, renderbuffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindTexture(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint texture = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindTexture(target, texture);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendColor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf red = info[0].As<Napi::Number>().FloatValue();
  GLclampf green = info[1].As<Napi::Number>().FloatValue();
  GLclampf blue = info[2].As<Napi::Number>().FloatValue();
  GLclampf alpha = info[3].As<Napi::Number>().FloatValue();
  this->instance->glBlendColor(red, green, blue, alpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendEquation(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum mode = info[0].As<Napi::Number>().Int32Value();
  this->instance->glBlendEquation(mode);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendEquationSeparate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum modeRGB = info[0].As<Napi::Number>().Int32Value();
  GLenum modeAlpha = info[1].As<Napi::Number>().Int32Value();
  this->instance->glBlendEquationSeparate(modeRGB, modeAlpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendFunc(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum sfactor = info[0].As<Napi::Number>().Int32Value();
  GLenum dfactor = info[1].As<Napi::Number>().Int32Value();
  this->instance->glBlendFunc(sfactor, dfactor);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendFuncSeparate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum srcRGB = info[0].As<Napi::Number>().Int32Value();
  GLenum dstRGB = info[1].As<Napi::Number>().Int32Value();
  GLenum srcAlpha = info[2].As<Napi::Number>().Int32Value();
  GLenum dstAlpha = info[3].As<Napi::Number>().Int32Value();
  this->instance->glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCheckFramebufferStatus(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum result = this->instance->glCheckFramebufferStatus(target);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glClearDepthf(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf depth = info[0].As<Napi::Number>().FloatValue();
  this->instance->glClearDepthf(depth);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glClearStencil(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint s = info[0].As<Napi::Number>().Int32Value();
  this->instance->glClearStencil(s);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glColorMask(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLboolean red = info[0].As<Napi::Boolean>().Value();
  GLboolean green = info[1].As<Napi::Boolean>().Value();
  GLboolean blue = info[2].As<Napi::Boolean>().Value();
  GLboolean alpha = info[3].As<Napi::Boolean>().Value();
  this->instance->glColorMask(red, green, blue, alpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCompileShader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glCompileShader(shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCopyTexImage2D(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 8) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLint level = info[1].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
  GLint x = info[3].As<Napi::Number>().Int32Value();
  GLint y = info[4].As<Napi::Number>().Int32Value();
  GLsizei width = info[5].As<Napi::Number>().Int32Value();
  GLsizei height = info[6].As<Napi::Number>().Int32Value();
  GLint border = info[7].As<Napi::Number>().Int32Value();
  this->instance->glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCopyTexSubImage2D(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 8) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLint level = info[1].As<Napi::Number>().Int32Value();
  GLint xoffset = info[2].As<Napi::Number>().Int32Value();
  GLint yoffset = info[3].As<Napi::Number>().Int32Value();
  GLint x = info[4].As<Napi::Number>().Int32Value();
  GLint y = info[5].As<Napi::Number>().Int32Value();
  GLsizei width = info[6].As<Napi::Number>().Int32Value();
  GLsizei height = info[7].As<Napi::Number>().Int32Value();
  this->instance->glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCreateProgram(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint result = this->instance->glCreateProgram();
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glCreateShader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum type = info[0].As<Napi::Number>().Int32Value();
  GLuint result = this->instance->glCreateShader(type);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glDeleteProgram(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDeleteProgram(program);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDeleteShader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDeleteShader(shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDepthMask(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLboolean flag = info[0].As<Napi::Boolean>().Value();
  this->instance->glDepthMask(flag);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDepthRangef(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf zNear = info[0].As<Napi::Number>().FloatValue();
  GLclampf zFar = info[1].As<Napi::Number>().FloatValue();
  this->instance->glDepthRangef(zNear, zFar);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDetachShader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLuint shader = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glDetachShader(program, shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDisableVertexAttribArray(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDisableVertexAttribArray(index);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFinish(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glFinish();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFlush(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glFlush();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFramebufferRenderbuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum attachment = info[1].As<Napi::Number>().Int32Value();
  GLenum renderbuffertarget = info[2].As<Napi::Number>().Int32Value();
  GLuint renderbuffer = info[3].As<Napi::Number>().Uint32Value();
  this->instance->glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFramebufferTexture2D(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum attachment = info[1].As<Napi::Number>().Int32Value();
  GLenum textarget = info[2].As<Napi::Number>().Int32Value();
  GLuint texture = info[3].As<Napi::Number>().Uint32Value();
  GLint level = info[4].As<Napi::Number>().Int32Value();
  this->instance->glFramebufferTexture2D(target, attachment, textarget, texture, level);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGenerateMipmap(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  this->instance->glGenerateMipmap(target);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGetError(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum result = this->instance->glGetError();
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glHint(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum mode = info[1].As<Napi::Number>().Int32Value();
  this->instance->glHint(target, mode);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint buffer = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsBuffer(buffer);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsEnabled(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum cap = info[0].As<Napi::Number>().Int32Value();
  GLboolean result = this->instance->glIsEnabled(cap);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsFramebuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint framebuffer = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsFramebuffer(framebuffer);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsProgram(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsProgram(program);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsRenderbuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint renderbuffer = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsRenderbuffer(renderbuffer);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsShader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsShader(shader);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsTexture(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint texture = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsTexture(texture);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glLineWidth(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLfloat width = info[0].As<Napi::Number>().FloatValue();
  this->instance->glLineWidth(width);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glLinkProgram(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glLinkProgram(program);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPixelStorei(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum pname = info[0].As<Napi::Number>().Int32Value();
  GLint param = info[1].As<Napi::Number>().Int32Value();
  this->instance->glPixelStorei(pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPolygonOffset(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLfloat factor = info[0].As<Napi::Number>().FloatValue();
  GLfloat units = info[1].As<Napi::Number>().FloatValue();
  this->instance->glPolygonOffset(factor, units);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glReleaseShaderCompiler(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glReleaseShaderCompiler();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glRenderbufferStorage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[1].As<Napi::Number>().Int32Value();
  GLsizei width = info[2].As<Napi::Number>().Int32Value();
  GLsizei height = info[3].As<Napi::Number>().Int32Value();
  this->instance->glRenderbufferStorage(target, internalformat, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glSampleCoverage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf value = info[0].As<Napi::Number>().FloatValue();
  GLboolean invert = info[1].As<Napi::Boolean>().Value();
  this->instance->glSampleCoverage(value, invert);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glScissor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint x = info[0].As<Napi::Number>().Int32Value();
  GLint y = info[1].As<Napi::Number>().Int32Value();
  GLsizei width = info[2].As<Napi::Number>().Int32Value();
  GLsizei height = info[3].As<Napi::Number>().Int32Value();
  this->instance->glScissor(x, y, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilFunc(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum func = info[0].As<Napi::Number>().Int32Value();
  GLint ref = info[1].As<Napi::Number>().Int32Value();
  GLuint mask = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glStencilFunc(func, ref, mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilFuncSeparate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum face = info[0].As<Napi::Number>().Int32Value();
  GLenum func = info[1].As<Napi::Number>().Int32Value();
  GLint ref = info[2].As<Napi::Number>().Int32Value();
  GLuint mask = info[3].As<Napi::Number>().Uint32Value();
  this->instance->glStencilFuncSeparate(face, func, ref, mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilMask(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint mask = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glStencilMask(mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilMaskSeparate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum face = info[0].As<Napi::Number>().Int32Value();
  GLuint mask = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glStencilMaskSeparate(face, mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilOp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum fail = info[0].As<Napi::Number>().Int32Value();
  GLenum zfail = info[1].As<Napi::Number>().Int32Value();
  GLenum zpass = info[2].As<Napi::Number>().Int32Value();
  this->instance->glStencilOp(fail, zfail, zpass);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilOpSeparate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum face = info[0].As<Napi::Number>().Int32Value();
  GLenum fail = info[1].As<Napi::Number>().Int32Value();
  GLenum zfail = info[2].As<Napi::Number>().Int32Value();
  GLenum zpass = info[3].As<Napi::Number>().Int32Value();
  this->instance->glStencilOpSeparate(face, fail, zfail, zpass);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexParameterf(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLfloat param = info[2].As<Napi::Number>().FloatValue();
  this->instance->glTexParameterf(target, pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexParameteri(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLint param = info[2].As<Napi::Number>().Int32Value();
  this->instance->glTexParameteri(target, pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glValidateProgram(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glValidateProgram(program);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib1f(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib1f(indx, x);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib2f(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  GLfloat y = info[2].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib2f(indx, x, y);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib3f(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  GLfloat y = info[2].As<Napi::Number>().FloatValue();
  GLfloat z = info[3].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib3f(indx, x, y, z);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib4f(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  GLfloat y = info[2].As<Napi::Number>().FloatValue();
  GLfloat z = info[3].As<Napi::Number>().FloatValue();
  GLfloat w = info[4].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib4f(indx, x, y, z, w);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glViewport(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint x = info[0].As<Napi::Number>().Int32Value();
  GLint y = info[1].As<Napi::Number>().Int32Value();
  GLsizei width = info[2].As<Napi::Number>().Int32Value();
  GLsizei height = info[3].As<Napi::Number>().Int32Value();
  this->instance->glViewport(x, y, width, height);
  return env.Null();
}
