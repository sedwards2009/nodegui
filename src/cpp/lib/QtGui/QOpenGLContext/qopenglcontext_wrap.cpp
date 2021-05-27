#include "QtCore/QObject/qobject_wrap.h"
#include "QtGui/QOpenGLContext/qopenglcontext_wrap.h"
#include "QtGui/QOpenGLFunctions/qopenglfunctions_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QOpenGLContextWrap::constructor;

Napi::Object QOpenGLContextWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLContext";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("functions", &QOpenGLContextWrap::functions),
      StaticMethod("currentContext", &StaticOpenGLContextWrapMethods::currentContext),
      COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLContextWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLContext* QOpenGLContextWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLContextWrap::QOpenGLContextWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLContextWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    if (info[0].IsExternal()) {
      this->instance = info[0].As<Napi::External<QOpenGLContext>>().Data();
      this->isOwnsInstance = false; // Instance was created elsewhere and shared with us.
    } else {
      Napi::Object parentObject = info[0].As<Napi::Object>();
      QObjectWrap* parentObjectWrap = Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
      this->instance = new QOpenGLContext(parentObjectWrap->getInternalInstance());
      this->isOwnsInstance = true;
    }
  } else if (info.Length() == 0) {
    this->instance = new QOpenGLContext();
    this->isOwnsInstance = true;
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLContextWrap::~QOpenGLContextWrap() {
  if (this->isOwnsInstance) {
    extrautils::safeDelete(this->instance);
  }
}

Napi::Value QOpenGLContextWrap::functions(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QOpenGLFunctions* functions = this->instance->functions();
  if (functions == nullptr) {
    return env.Null();
  }

  auto instance = QOpenGLFunctionsWrap::constructor.New({Napi::External<QOpenGLFunctions>::New(env, functions)});
  return instance;
}

Napi::Value StaticOpenGLContextWrapMethods::currentContext(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QOpenGLContext* context = QOpenGLContext::currentContext();
  if (context == nullptr) {
    return env.Null();
  }
  auto instance = QOpenGLContextWrap::constructor.New({Napi::External<QOpenGLContext>::New(
      env, context)});
  return instance;
}
