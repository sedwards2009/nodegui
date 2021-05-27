#pragma once

#include <napi.h>

#include <QOpenGLFunctions>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QOpenGLFunctionsWrap : public Napi::ObjectWrap<QOpenGLFunctionsWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QOpenGLFunctions* instance;
  bool isOwnsInstance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLFunctionsWrap(const Napi::CallbackInfo& info);
  ~QOpenGLFunctionsWrap();
  QOpenGLFunctions* getInternalInstance();
  // Wrapped methods
  Napi::Value initializeOpenGLFunctions(const Napi::CallbackInfo& info);
  Napi::Value glClearColor(const Napi::CallbackInfo& info);
  Napi::Value glClear(const Napi::CallbackInfo& info);
  Napi::Value glFrontFace(const Napi::CallbackInfo& info);
  Napi::Value glCullFace(const Napi::CallbackInfo& info);
  Napi::Value glEnable(const Napi::CallbackInfo& info);
};
