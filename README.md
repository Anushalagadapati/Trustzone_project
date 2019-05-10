# Trustzone_project

This folder contains TA and CA apis documents.
votarytech trustzone HLD documents and ppts.

#########################Project####################

##plateform identification


add header.h in qemu/optee_os/lib/libutee/include
add tee_platestruct.c in qemu/optee_os/lib/libutee
add tee_platestruct.o in qemu/optee_os/lib/libutee/sub.mk 


##votary apis


add vee_optee.h in qemu/optee_os/lib/libutee/include
add vee_optee.c in qemu/optee_os/lib/libutee 
add vee_optee.o in qemu/optee_os/lib/libutee/sub.mk


##hello_world

in ta.c use vee api's and call platform_structure_info() in initialize context.




