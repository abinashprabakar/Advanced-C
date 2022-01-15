
section .text
	global _start
_start:
	mov rax,1	/*!	rax --> i	*/ 
	mov rbx,2	/*!	rbx --> j	*/
	mov rcx,0	/*! 	tcx --> sum 	*/
	mov rax,rbx	/*! 	i = j		*/
loop:
	cmp rax,5	/*!	i < 5 		*/
	je complete
	mov rdx,rax	/*!	rdx --> temp	*/
	and rdx,1	/*!	i % 2 == 0	*/
	jnz loop1	/*! 	if odd goto loop1	*/
	add rcx,rax	/*!	sum += i	*/
loop1:
	add rax,1	/*! 	i++ 		*/
	jmp loop	/*! 	goto loop 	*/
complete:
	  
	
