/*
 * Authors:Kamlesh Patil,Pushpa Methekar
 * Email id:kamlesh.patil@votarytech.com,pushpa.methekar@votarytech.com
 */


#ifndef __VEE_OPTEE_H__ 
#define __VEE_OPTEE_H__

#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>


#define VEE_ERROR			0
#define VEE_SUCCESS 			1
#define VEE_PARAM_TYPES(t0,t1,t2,t3) \
	((t0) | ((t1) << 4) | ((t2) << 8) | ((t3) << 12))
#define VEE_PARAM_TYPE_NONE             0
#define VEE_PARAM_TYPE_VALUE_INPUT      1
#define VEE_PARAM_TYPE_VALUE_OUTPUT     2
#define VEE_PARAM_TYPE_VALUE_INOUT      3

typedef uint32_t  VEE_Result;

struct VEE_t{

	uint32_t VEE_param_types; 	//VEE_param_types determines parameter types.
	void **VEE_sess_ctx;	  	//VEE_sess_ctx is pointer which holds address of session. 
	TEE_Param *VEE_Params;   	//VEE_params is pointer variable of TEE_params union. 
	uint32_t VEE_cmd_id;		//VEE_cmd_id is field value which maps user defined function.


}VEE_parameter;

/*
 *VEE API prototypes declared.
 */
VEE_Result VEE_CreateEntryPoint(void);

void VEE_DestroyEntryPoint(void);

VEE_Result VEE_OpenSessionEntryPoint(struct VEE_t VEE_args);

VEE_Result VEE_InvokeCommandEntryPoint(struct VEE_t *VEE_args);

void VEE_CloseSessionEntryPoint(struct VEE_t VEE_args);



#endif
