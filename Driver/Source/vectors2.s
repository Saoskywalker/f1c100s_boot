

	AREA Vect2, CODE, READONLY




				EXPORT	Vector_Table_2
			
Vector_Table_2
        LDR     PC, IRQ_NMI          ;= 0, 
	      LDR     PC, IRQ_UART0        ;= 1,
	      LDR     PC, IRQ_UART1        ;= 2,
	      LDR     PC, IRQ_UART2        ;= 3,	
        NOP      
	      LDR     PC, IRQ_OWA       	 ;= 5,
	      LDR     PC, IRQ_CIR      	   ;= 6,
	      LDR     PC, IRQ_TWI0     	 	 ;= 7,
	      LDR     PC, IRQ_TWI1     		 ;= 8,
	      LDR     PC, IRQ_TWI2       	 ;= 9,
	      LDR     PC, IRQ_SPI0         ;= 10,
	      LDR     PC, IRQ_SPI1         ;= 11,
        NOP      
	      LDR     PC, IRQ_Timer0       ;= 13,
	      LDR     PC, IRQ_Timer1       ;= 14,
	      LDR     PC, IRQ_Timer2       ;= 15,	
	      LDR     PC, IRQ_Watchdog     ;= 16,
	      LDR     PC, IRQ_RSB          ;= 17,
	      LDR     PC, IRQ_DMA          ;= 18,
        NOP      
	      LDR     PC, IRQ_Touch_Panel  ;= 20,
	      LDR     PC, IRQ_Aucio_Codec  ;= 21,
	      LDR     PC, IRQ_KEYADC       ;= 22,
	      LDR     PC, IRQ_SDC0         ;= 23,
	      LDR     PC, IRQ_SDC1         ;= 24,
        NOP      
	      LDR     PC, IRQ_USG_OTG      ;= 26,
	      LDR     PC, IRQ_TVD          ;= 27,
	      LDR     PC, IRQ_TVE          ;= 28,
	      LDR     PC, IRQ_TCON         ;= 29,
	      LDR     PC, IRQ_DE_FE        ;= 30,
	      LDR     PC, IRQ_DE_BE        ;= 31,
	      LDR     PC, IRQ_CSI          ;= 32,
	      LDR     PC, IRQ_DE_interlace ;= 33,
	      LDR     PC, IRQ_VE           ;= 34,
	      LDR     PC, IRQ_DAUDIO       ;= 35,
        NOP      
        NOP      
	      LDR     PC, IRQ_PIOD      	 ;= 38,
	      LDR     PC, IRQ_PIOE      	 ;= 39,
	      LDR     PC, IRQ_PIOF      	 ;= 40,

				
IRQ_NMI          DCD    IRQ_NMI_Handler          		;= 0, 
IRQ_UART0        DCD    IRQ_UART0_Handler          	;= 1,
IRQ_UART1        DCD    IRQ_UART1_Handler           ;= 2,
IRQ_UART2        DCD    IRQ_UART2_Handler        	  ;= 3,	
				         DCD		0
IRQ_OWA       	 DCD    IRQ_OWA_Handler       			;= 5,
IRQ_CIR        	 DCD    IRQ_CIR_Handler        	  	;= 6,
IRQ_TWI0       	 DCD    IRQ_TWI0_Handler      	  	;= 7,
IRQ_TWI1         DCD    IRQ_TWI1_Handler      			;= 8,
IRQ_TWI2         DCD    IRQ_TWI2_Handler          	;= 9,
IRQ_SPI0         DCD    IRQ_SPI0_Handler         		;= 10,
IRQ_SPI1         DCD    IRQ_SPI1_Handler         		;= 11,
				         DCD		0
IRQ_Timer0       DCD    IRQ_Timer0_Handler          ;= 13,
IRQ_Timer1       DCD    IRQ_Timer1_Handler       		;= 14,
IRQ_Timer2       DCD    IRQ_Timer2_Handler       		;= 15,	
IRQ_Watchdog     DCD    IRQ_Watchdog_Handler      	;= 16,
IRQ_RSB          DCD    IRQ_RSB_Handler         		;= 17,
IRQ_DMA          DCD    IRQ_DMA_Handler          		;= 18,
				         DCD		0
IRQ_Touch_Panel  DCD    IRQ_Touch_Panel_Handler   	;= 20,
IRQ_Aucio_Codec  DCD    IRQ_Aucio_Codec_Handler   	;= 21,
IRQ_KEYADC       DCD    IRQ_KEYADC_Handler         	;= 22,
IRQ_SDC0         DCD    IRQ_SDC0_Handler         		;= 23,
IRQ_SDC1         DCD    IRQ_SDC1_Handler         		;= 24,
				         DCD		0
IRQ_USG_OTG      DCD    IRQ_USG_OTG_Handler      		;= 26,
IRQ_TVD          DCD    IRQ_TVD_Handler         		;= 27,
IRQ_TVE          DCD    IRQ_TVE_Handler          		;= 28,
IRQ_TCON         DCD    IRQ_TCON_Handler         		;= 29,
IRQ_DE_FE        DCD    IRQ_DE_FE_Handler         	;= 30,
IRQ_DE_BE        DCD    IRQ_DE_BE_Handler         	;= 31,
IRQ_CSI          DCD    IRQ_CSI_Handler        			;= 32,
IRQ_DE_interlace DCD    IRQ_DE_interlace_Handler  	;= 33,
IRQ_VE           DCD    IRQ_VE_Handler 							;= 34,
IRQ_DAUDIO       DCD    IRQ_DAUDIO_Handler   				;= 35,
				         DCD		0
				         DCD		0
IRQ_PIOD         DCD    IRQ_PIOD_Handler     	 			;= 38,
IRQ_PIOE         DCD    IRQ_PIOE_Handler      	 		;= 39,
IRQ_PIOF         DCD    IRQ_PIOF_Handler       	 		;= 40,

 IMPORT	 IRQ_TCON_Handler1
 IMPORT	 IRQ_OWA_Handler1
 IMPORT	 IRQ_TCON_Handler2	
	
IRQ_NMI_Handler          		;= 0, 
				B  	IRQ_NMI_Handler
IRQ_UART0_Handler          	;= 1,
				B		IRQ_TCON_Handler1
IRQ_UART1_Handler           ;= 2,
				B		IRQ_TCON_Handler1
IRQ_UART2_Handler        	  ;= 3,	
				B		IRQ_TCON_Handler1
		NOP
IRQ_OWA_Handler       			;= 5,
				B		IRQ_TCON_Handler1
IRQ_CIR_Handler        	  	;= 6,
				B		IRQ_TCON_Handler1
IRQ_TWI0_Handler      	  	;= 7,
				B		IRQ_TCON_Handler1
IRQ_TWI1_Handler      			;= 8,
				B		IRQ_TCON_Handler1 
IRQ_TWI2_Handler          	;= 9,
				B		IRQ_TCON_Handler1
IRQ_SPI0_Handler         		;= 10,
				B		IRQ_TCON_Handler1
IRQ_SPI1_Handler         		;= 11,
				B		IRQ_TCON_Handler1 
		NOP
IRQ_Timer0_Handler          ;= 13,
				B		IRQ_TCON_Handler1
IRQ_Timer1_Handler       		;= 14,
				B		IRQ_TCON_Handler1
IRQ_Timer2_Handler       		;= 15,
				B		IRQ_TCON_Handler1
IRQ_Watchdog_Handler      	;= 16,
				B		IRQ_TCON_Handler1
IRQ_RSB_Handler         		;= 17,
				B		IRQ_TCON_Handler1 
IRQ_DMA_Handler          		;= 18,
				B		IRQ_TCON_Handler1
		NOP
IRQ_Touch_Panel_Handler   	;= 20,
				B		IRQ_TCON_Handler1 
IRQ_Aucio_Codec_Handler   	;= 21,
				B		IRQ_TCON_Handler1
IRQ_KEYADC_Handler         	;= 22,
				B		IRQ_TCON_Handler1
IRQ_SDC0_Handler         		;= 23,
				B		IRQ_TCON_Handler1
IRQ_SDC1_Handler         		;= 24,
				B		IRQ_TCON_Handler1
		NOP
IRQ_USG_OTG_Handler      		;= 26,
				B		IRQ_TCON_Handler1
IRQ_TVD_Handler         		;= 27,
				B		IRQ_TCON_Handler1
IRQ_TVE_Handler          		;= 28,
				B		IRQ_TCON_Handler1
IRQ_TCON_Handler         		;= 29,
				B		IRQ_TCON_Handler
IRQ_DE_FE_Handler         	;= 30,
				B		IRQ_TCON_Handler1
IRQ_DE_BE_Handler         	;= 31,
				B		IRQ_TCON_Handler1
IRQ_CSI_Handler        			;= 32,
				B		IRQ_TCON_Handler1
IRQ_DE_interlace_Handler  	;= 33,
				B		IRQ_TCON_Handler1
IRQ_VE_Handler 							;= 34,
				B		IRQ_TCON_Handler1
IRQ_DAUDIO_Handler   				;= 35,
				B		IRQ_TCON_Handler1
		NOP
		NOP
IRQ_PIOD_Handler     	 			;= 38,
				B		IRQ_TCON_Handler1
IRQ_PIOE_Handler      	 		;= 39,
				B		IRQ_TCON_Handler1
IRQ_PIOF_Handler       	 		;= 40,		
				B		IRQ_TCON_Handler1		
		
        END

