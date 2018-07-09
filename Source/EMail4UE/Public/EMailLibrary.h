#pragma once
#include "EngineMinimal.h"
#include "EMailLibrary.generated.h"

UCLASS()
class UEMailLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "EMAIL")
		static bool SendEMail(const FString& EMail, const FString& Pass, const FString& Tittle, const FString& Body);


};