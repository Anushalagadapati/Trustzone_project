/*
 * Authors:Kamlesh Patil,Pushpa Methekar
 * Email id:kamlesh.patil@votarytech.com,pushpa.methekar@votarytech.com
 */

#include <vee_optee.h>

VEE_Result VEE_res;

/*
 *TA_CreateEntryPoint() is calling VEE_CreateEntryPoint().
 */
TEE_Result TA_CreateEntryPoint(void)
{

	VEE_CreateEntryPoint();

	return TEE_SUCCESS;
}

/*
 * TA_DestroyEntryPoint() is calling VEE_DestroyEntryPoint().
 */
void TA_DestroyEntryPoint(void)
{
	VEE_DestroyEntryPoint();
}

/*
 *TA_OpenSessionEntryPoint() is calling VEE_OpenSessionEntryPoint().
 * Which accepts param_types,params,session ctx as parameters.
 */
TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types,
		TEE_Param __maybe_unused params[4],
		void __maybe_unused **sess_ctx)
{
	VEE_parameter.VEE_param_types=param_types;
	VEE_parameter.VEE_sess_ctx=sess_ctx;
	VEE_parameter.VEE_Params=&params;

	VEE_res=VEE_OpenSessionEntryPoint(VEE_parameter);

	if(VEE_res==VEE_ERROR)
		return TEE_ERROR_BAD_PARAMETERS;

	return TEE_SUCCESS;
}

/*
 *TA_CloseSessionEntryPoint() is calling VEE_CloseSessionEntryPoint().
 *Which accepts session ctx as parameters.
 */
void TA_CloseSessionEntryPoint(void __maybe_unused *sess_ctx)
{

	VEE_CloseSessionEntryPoint(VEE_parameter);
}



/*
 *TA_InvokeCommandEntryPoint() is calling VEE_InvokeCommandEntryPoint().
 *Which accepts session ctx,command id,param types,params as parameters.
 */
TEE_Result TA_InvokeCommandEntryPoint(void __maybe_unused *sess_ctx,
		uint32_t cmd_id,
		uint32_t param_types, TEE_Param params[4])
{
	VEE_parameter.VEE_sess_ctx=&sess_ctx;
	VEE_parameter.VEE_cmd_id=cmd_id;
	VEE_parameter.VEE_param_types=param_types;
	VEE_parameter.VEE_Params=params;
	VEE_res=VEE_InvokeCommandEntryPoint(&VEE_parameter);

	return TEE_SUCCESS;
}
