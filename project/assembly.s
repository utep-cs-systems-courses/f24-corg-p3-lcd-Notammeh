    .section .text                ; Text section for code
    .global toggle_led_asm        ; Make the function accessible to C

toggle_led_asm:
    mov.b &P1OUT, r15             ; Load P1OUT into register r15
    xor.b #BIT6, r15              ; Toggle BIT6 (P1.6, LED pin)
    mov.b r15, &P1OUT             ; Write the result back to P1OUT
	ret                           ; Return to caller
	
