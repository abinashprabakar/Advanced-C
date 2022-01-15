.global _start
_start:
	
	mov r0,#0	# i = 0
	mov r1,#0	# sum = 0
	
	.loop:		# loop
	cmp r0,#9	# i < 10
	bgt .last
	add r1,r1,r0	# sum += i
	add r0,r0,#1	# i++
	b .loop		# goback to loop if i<10
	
	.last:
