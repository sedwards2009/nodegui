#include "QtGui/QOpenGLContext/qopenglcontext_wrap.h"
#include "QtGui/QOpenGLFunctions/qopenglfunctions_wrap.h"

#include "Extras/Utils/nutils.h"


Napi::FunctionReference QOpenGLFunctionsWrap::constructor;

Napi::Object QOpenGLFunctionsWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLFunctions";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("initializeOpenGLFunctions", &QOpenGLFunctionsWrap::initializeOpenGLFunctions),
                  InstanceMethod("glClearColor", &QOpenGLFunctionsWrap::glClearColor),
                  InstanceMethod("glClear", &QOpenGLFunctionsWrap::glClear),
                  InstanceMethod("glFrontFace", &QOpenGLFunctionsWrap::glFrontFace),
                  InstanceMethod("glCullFace", &QOpenGLFunctionsWrap::glCullFace),
                  InstanceMethod("glEnable", &QOpenGLFunctionsWrap::glEnable),
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
