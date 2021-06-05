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
