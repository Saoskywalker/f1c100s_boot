
	PRESERVE8
	AREA Vect1, CODE, READONLY



        EXPORT	Vector_Table_1
Vector_Table_1		
        B       Reset_Go
        LDR     PC, Undefined_Addr
        LDR     PC, SWI_Addr
        LDR     PC, Prefetch_Addr
        LDR     PC, Abort_Addr
        NOP                             ; Reserved vector
        LDR     PC, IRQ_Addr
        LDR     PC, FIQ_Addr
        
				
        IMPORT  Reset_Go           ; In sys_start.s
        
Reset_Addr      DCD     Reset_Go
Undefined_Addr  DCD     Undefined_Handler
SWI_Addr        DCD     SWI_Handler
Prefetch_Addr   DCD     Prefetch_Handler
Abort_Addr      DCD     Abort_Handler
				        DCD		  0
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler


; ************************
; Exception Handlers
; ************************

; The following dummy handlers do not do anything useful in this example.
; They are set up here for completeness.
 ;IMPORT  SWI_Handler1
 ;IMPORT	 IRQ_Handler1

Undefined_Handler
        B       Undefined_Handler
SWI_Handler
		B 			SWI_Handler 
Prefetch_Handler
        B       Prefetch_Handler
Abort_Handler
        B       Abort_Handler
		NOP
IRQ_Handler
        B       IRQ_Handler
FIQ_Handler
        B       FIQ_Handler
				

END
