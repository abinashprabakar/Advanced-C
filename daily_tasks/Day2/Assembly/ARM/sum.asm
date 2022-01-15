
/*

	int i = 1;
	int j = 2;
	int sum = 0;
	
	for(i=j; i<5; i++)
	{
		if(i%2 == 0)
		{
			sum += i;
		}
	}

The below ARM assembly code is equivalent of the above c code.




*/






.global _start
_start:
	mov r0,#1;	/*! r0 --->  i,  i = 0 */
	mov r1,#2;	/*!  j = 2  */
	mov r3,#0;	/*!  sum = 0   */
	mov r0,r1;	/*!  i = j */
	loop:
	cmp r0,#5;	/*!  i < 5 */
	beq complete	/*! if i greater than 5 goto to end of the code */
	mov r4,r0;	/*! taking r4 as temp variable and moving r0 (i) value into r4 */
	ands r4,#1	/*! checking r4 (i) even or not by checking the 0th bit */
	addeq r3,r3,r0;	/*! if even adding the r0 (i) value to the r3 (sum) */
	add r0,r0,#1;	/*! incrementing r0 (i) value */
	b loop		/*! goto loop */
	complete:
