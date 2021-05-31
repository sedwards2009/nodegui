#include "QtGui/QOpenGLContext/qopenglcontext_wrap.h"
#include "QtGui/QOpenGLFunctions/qopenglfunctions_wrap.h"

#include "Extras/Utils/nutils.h"


Napi::FunctionReference QOpenGLFunctionsWrap::constructor;

Napi::Object QOpenGLFunctionsWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLFunctions";
  Napi::Function func =
      DefineClass(env, CLASSNAME, {
                  InstanceMethod("glBindBuffer", &QOpenGLFunctionsWrap::glBindBuffer),
                  InstanceMethod("glClear", &QOpenGLFunctionsWrap::glClear),
                  InstanceMethod("glClearColor", &QOpenGLFunctionsWrap::glClearColor),
                  InstanceMethod("glCullFace", &QOpenGLFunctionsWrap::glCullFace),
                  InstanceMethod("glDepthFunc", &QOpenGLFunctionsWrap::glDepthFunc),
                  InstanceMethod("glDisable", &QOpenGLFunctionsWrap::glDisable),
                  InstanceMethod("glDrawArrays", &QOpenGLFunctionsWrap::glDrawArrays),
                  InstanceMethod("glEnable", &QOpenGLFunctionsWrap::glEnable),
                  InstanceMethod("glFrontFace", &QOpenGLFunctionsWrap::glFrontFace),
                  InstanceMethod("glGetString", &QOpenGLFunctionsWrap::glGetString),
                  InstanceMethod("glUseProgram", &QOpenGLFunctionsWrap::glUseProgram),
                  InstanceMethod("initializeOpenGLFunctions", &QOpenGLFunctionsWrap::initializeOpenGLFunctions),
                  COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLFunctionsWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLFunctions* QOpenGLFunctionsWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLFunctionsWrap::QOpenGLFunctionsWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLFunctionsWrap>(info), isOwnsInstance(true) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 0) {
    this->instance = new QOpenGLFunctions();
  } else if (info.Length() == 1) {
    if (info[0].IsExternal()) {
      this->instance = info[0].As<Napi::External<QOpenGLFunctions>>().Data();
      this->isOwnsInstance = false;
    } else {
      Napi::Object contextObject = info[0].As<Napi::Object>();
      QOpenGLContextWrap* contextWrap = Napi::ObjectWrap<QOpenGLContextWrap>::Unwrap(contextObject);
      QOpenGLContext* context = contextWrap->getInternalInstance();
      this->instance = new QOpenGLFunctions(context);
    }
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLFunctionsWrap::~QOpenGLFunctionsWrap() {
  if (this->isOwnsInstance) {
    delete this->instance;
  }
}

Napi::Value QOpenGLFunctionsWrap::initializeOpenGLFunctions(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->initializeOpenGLFunctions();
  return env.Null();
}

Napi::Value QOpenGLFunctionsWrap::glBindBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint bufferId = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindBuffer(target, bufferId);
  return env.Null();
}

Napi::Value QOpenGLFunctionsWrap::glClearColor(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glClear(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glFrontFace(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glCullFace(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glDisable(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glEnable(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glDrawArrays(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glUseProgram(const Napi::CallbackInfo& info) {
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

Napi::Value QOpenGLFunctionsWrap::glGetString(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
      Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
  }

  GLenum name = info[0].As<Napi::Number>().Uint32Value();
  QString result( (const char *)(this->instance->glGetString(name)));
  return Napi::String::New(env, result.toStdString());
}

Napi::Value QOpenGLFunctionsWrap::glDepthFunc(const Napi::CallbackInfo& info) {
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
