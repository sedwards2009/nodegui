#include "QtGui/QOpenGLVertexArrayObject/qopenglvertexarrayobject_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtCore/QObject/qobject_wrap.h"


Napi::FunctionReference QOpenGLVertexArrayObjectWrap::constructor;

Napi::Object QOpenGLVertexArrayObjectWrap::init(Napi::Env env,
                                            Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLVertexArrayObject";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("bind", &QOpenGLVertexArrayObjectWrap::bind),
      InstanceMethod("create", &QOpenGLVertexArrayObjectWrap::create),
      InstanceMethod("release", &QOpenGLVertexArrayObjectWrap::release),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLVertexArrayObjectWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLVertexArrayObject* QOpenGLVertexArrayObjectWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLVertexArrayObjectWrap::QOpenGLVertexArrayObjectWrap(
    const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLVertexArrayObjectWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QObjectWrap* parentObjectWrap =
        Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
    this->instance =
        new QOpenGLVertexArrayObject(parentObjectWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new QOpenGLVertexArrayObject();
  } else {
    Napi::TypeError::New(env,
                         "Wrong number of arguments to "
                         "QOpenGLVertexArrayObjectWrap::QOpenGLVertexArrayObjectWrap()")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLVertexArrayObjectWrap::~QOpenGLVertexArrayObjectWrap() {
  extrautils::safeDelete(this->instance);
}

Napi::Value QOpenGLVertexArrayObjectWrap::bind(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->bind();
  return env.Null();
}

Napi::Value QOpenGLVertexArrayObjectWrap::create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->create();
  return Napi::Boolean::New(env, result);
}


Napi::Value QOpenGLVertexArrayObjectWrap::release(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->release();
  return env.Null();
}
