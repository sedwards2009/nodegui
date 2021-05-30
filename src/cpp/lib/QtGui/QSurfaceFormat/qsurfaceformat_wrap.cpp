#include "QtCore/QObject/qobject_wrap.h"
#include "QtGui/QSurfaceFormat/qsurfaceformat_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QSurfaceFormatWrap::constructor;

Napi::Object QSurfaceFormatWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QSurfaceFormat";
  Napi::Function func = DefineClass(
      env, CLASSNAME, {
      InstanceMethod("setDepthBufferSize", &QSurfaceFormatWrap::setDepthBufferSize),
      InstanceMethod("setStencilBufferSize", &QSurfaceFormatWrap::setStencilBufferSize),
      StaticMethod("setDefaultFormat", &StaticQSurfaceFormatWrapMethods::setDefaultFormat),
      COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLBufferWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QSurfaceFormat* QSurfaceFormatWrap::getInternalInstance() {
  return this->instance;
}

QSurfaceFormatWrap::QSurfaceFormatWrap(const Napi::CallbackInfo& info) : Napi::ObjectWrap<QSurfaceFormatWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance = new QSurfaceFormat();
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QSurfaceFormatWrap::~QSurfaceFormatWrap() {
  delete this->instance;
}

Napi::Value QSurfaceFormatWrap::setDepthBufferSize(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int size = info[0].As<Napi::Number>().Int32Value();
  this->instance->setDepthBufferSize(size);
  return env.Null();
}

Napi::Value QSurfaceFormatWrap::setStencilBufferSize(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int size = info[0].As<Napi::Number>().Int32Value();
  this->instance->setStencilBufferSize(size);
  return env.Null();
}

Napi::Value StaticQSurfaceFormatWrapMethods::setDefaultFormat(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object surfaceFormatObject = info[0].As<Napi::Object>();
  QSurfaceFormatWrap* surfaceFormatWrap = Napi::ObjectWrap<QSurfaceFormatWrap>::Unwrap(surfaceFormatObject);
  QSurfaceFormat::setDefaultFormat(*surfaceFormatWrap->getInternalInstance());
  return env.Null();
}
