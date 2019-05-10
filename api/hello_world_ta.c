/*
 * Copyright (c) 2018, Votary softtech Private Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#include <hello_world_ta.h>
#include <vee_optee.h>

/*
 * Called when the instance of the TA is created. This is the first call in
 * the TA 
 */


VEE_Result VEE_CreateEntryPoint(void)
{
	DMSG(" IN ta.c :has been called");

	return VEE_SUCCESS;
}

/*
 * Called when the instance of the TA is destroyed if the TA has not
 * crashed or panicked. This is the last call in the TA.
 */
void VEE_DestroyEntryPoint(void)
{
	DMSG("in ta.c:has been called");
}

/*
 * Called when a new session is opened to the TA. *VEE_sess_ctx can be updated
 * with a value to be able to identify this session in subsequent calls to the
 * TA. In this function you will normally do the global initialization for the
 * TA. VEE_OpenSessionEntryPoint() accepts argument as a struct VEE_t variable. 
 */
VEE_Result VEE_OpenSessionEntryPoint(struct VEE_t VEE_args)
{
	uint32_t exp_param_types = VEE_PARAM_TYPES(VEE_PARAM_TYPE_NONE,
			VEE_PARAM_TYPE_NONE,
			VEE_PARAM_TYPE_NONE,
			VEE_PARAM_TYPE_NONE);

	DMSG("in ta.c :has been called");

	if (VEE_args.VEE_param_types != exp_param_types)
		return VEE_ERROR;



	IMSG("Hello World!\n");

	return VEE_SUCCESS;
}

/*
 * Called when a session is closed, VEE_sess_ctx hold the value that was
 * assigned by VEE_OpenSessionEntryPoint().VEE_OpenSessionEntryPoint() 
 *accepts argument as a struct VEE_t variable. 
 */

void VEE_CloseSessionEntryPoint(struct VEE_t VEE_args)
{

	IMSG("Goodbye!\n");
}

/*
 *user defined function called by VEE_InvokeCommandEntryPoint.
 *inc_value() accepts struct VEE_t variable address.
 */
static VEE_Result inc_value(struct VEE_t **VEE_args)
{
	uint32_t exp_param_types = VEE_PARAM_TYPES(VEE_PARAM_TYPE_VALUE_INOUT,
			VEE_PARAM_TYPE_NONE,
			VEE_PARAM_TYPE_NONE,
			VEE_PARAM_TYPE_NONE);

	DMSG("has been called");

	if ((*VEE_args)->VEE_param_types != exp_param_types)
		return VEE_ERROR;

	IMSG("Got value: %u from NW",(*VEE_args)->VEE_Params->value.a);
	(*VEE_args)->VEE_Params->value.a++;
	IMSG("Increase value to: %u",(*VEE_args)->VEE_Params->value.a);

	return VEE_SUCCESS;
}


/* 
 *Invokes the functionality of user defined function.
 *VEE_InvokeCommandEntryPoint() accepts struct VEE_t variable address.
 */
VEE_Result VEE_InvokeCommandEntryPoint(struct VEE_t *VEE_args)
{

	switch (VEE_args->VEE_cmd_id) {
		case TA_HELLO_WORLD_CMD_INC_VALUE:
			return inc_value(&VEE_args);
		default:
			return VEE_ERROR;
	}
}

