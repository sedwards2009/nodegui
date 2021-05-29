#include "QtCore/QObject/qobject_wrap.h"
#include "QtGui/QOpenGLShader/qopenglshader_wrap.h"
#include "QtGui/QOpenGLShaderProgram/qopenglshaderprogram_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QOpenGLShaderProgramWrap::constructor;

Napi::Object QOpenGLShaderProgramWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLShaderProgram";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("addShader", &QOpenGLShaderProgramWrap::addShader),
      InstanceMethod("link", &QOpenGLShaderProgramWrap::link),
      InstanceMethod("attributeLocation", &QOpenGLShaderProgramWrap::attributeLocation),
      InstanceMethod("uniformLocation", &QOpenGLShaderProgramWrap::uniformLocation),
      COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLShaderProgramWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLShaderProgram* QOpenGLShaderProgramWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLShaderProgramWrap::QOpenGLShaderProgramWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLShaderProgramWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QObjectWrap* parentObjectWrap = Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
    this->instance = new QOpenGLShaderProgram(parentObjectWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new QOpenGLShaderProgram();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments to QOpenGLShaderProgramWrap::QOpenGLShaderProgramWrap()")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLShaderProgramWrap::~QOpenGLShaderProgramWrap() {
  extrautils::safeDelete(this->instance);
}

Napi::Value QOpenGLShaderProgramWrap::addShader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
      Napi::TypeError::New(env, "Wrong number of arguments to QOpenGLShaderProgramWrap::addShader()")
          .ThrowAsJavaScriptException();
  }

  Napi::Object shaderObject = info[0].As<Napi::Object>();
  QOpenGLShaderWrap* shaderWrap = Napi::ObjectWrap<QOpenGLShaderWrap>::Unwrap(shaderObject);
  QOpenGLShader* shader = shaderWrap->getInternalInstance();
  bool result = this->instance->addShader(shader);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::link(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->link();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::attributeLocation(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
      Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
  }

  QString attribute = QString::fromStdString(info[0].As<Napi::String>().Utf8Value());
  auto result = this->instance->attributeLocation(attribute);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::uniformLocation(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
      Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
  }

  QString uniform = QString::fromStdString(info[0].As<Napi::String>().Utf8Value());
  auto result = this->instance->attributeLocation(uniform);
  return Napi::Number::New(env, result);
}
