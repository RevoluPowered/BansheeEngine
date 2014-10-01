#include "BsScriptDebug.h"
#include "BsMonoManager.h"
#include "BsMonoClass.h"
#include "BsMonoUtil.h"
#include "BsDebug.h"

namespace BansheeEngine
{
	ScriptDebug::ScriptDebug(MonoObject* instance)
		:ScriptObject(instance)
	{ }

	void ScriptDebug::initRuntimeData()
	{
		metaData.scriptClass->addInternalCall("Internal_Log", &ScriptDebug::internal_log);
		metaData.scriptClass->addInternalCall("Internal_LogWarning", &ScriptDebug::internal_logWarning);
		metaData.scriptClass->addInternalCall("Internal_LogError", &ScriptDebug::internal_logError);
	}

	void ScriptDebug::internal_log(MonoString* message)
	{
		gDebug().log(MonoUtil::monoToString(message), "ScriptInfo");
	}

	void ScriptDebug::internal_logWarning(MonoString* message)
	{
		gDebug().log(MonoUtil::monoToString(message), "ScriptWarning");
	}

	void ScriptDebug::internal_logError(MonoString* message)
	{
		gDebug().log(MonoUtil::monoToString(message), "ScriptError");
	}
}