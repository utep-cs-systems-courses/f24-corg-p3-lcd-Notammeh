    .global assembly  ; Make the function accessible in C
    .section .text     ; Code section

toggleLed:
    ; Load the P1OUT register address
    mov.w   &0x0021, r12  ; P1OUT address (register 0x21)

    ; XOR the red and green LED bits
    xor.w   #0x41, r12    ; Toggle bits (LED_RED = 0x01, LED_GREEN = 0x40)

    ; Write back to P1OUT
    mov.w   r12, &0x0021

	ret                   ; Return to the caller

	
