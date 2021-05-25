#include "QtCore/QObject/qobject_wrap.h"
#include "QtGui/QOpenGLContext/qopenglcontext_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QOpenGLContextWrap::constructor;

Napi::Object QOpenGLContextWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLContext";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {StaticMethod("currentContext", &StaticOpenGLContextWrapMethods::currentContext),
      COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLContextWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLContext* QOpenGLContextWrap::getInternalInstance() { return this->instance; }

QOpenGLContextWrap::~QOpenGLContextWrap() { extrautils::safeDelete(this->instance); }

QOpenGLContextWrap::QOpenGLContextWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLContextWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    if (info[0].IsExternal()) {
      this->instance = info[0].As<Napi::External<QOpenGLContext>>().Data();
    } else {
      Napi::Object parentObject = info[0].As<Napi::Object>();
      QObjectWrap* parentObjectWrap = Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
      this->instance = new QOpenGLContext(parentObjectWrap->getInternalInstance());
    }
  } else if (info.Length() == 0) {
    this->instance = new QOpenGLContext();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
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
