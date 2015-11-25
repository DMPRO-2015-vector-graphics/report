void write_program(){

	/* Wait for FPGA to be flashed, before writing to SRAM */
	while(GPIO_PinInGet(PORT_DONE, SIG_DONE) == 1);

	/* Clear CS1 to give control to EFM */
	GPIO_PinOutClear(gpioPortD, 10);

	for(uint16_t i = 0; i < size; i++){
		ebi_write(i, program_data[i]);
	}

	ebi_disable();

	/* Set up CS0, for manual control, as the processor do 
		not have control over this signal */
	GPIO_PinModeSet( gpioPortD,  9, gpioModePushPull, 0);

	/* Set CS1 to give control to FPGA */
	GPIO_PinOutSet(gpioPortD, 10);
	/* Set CS0 low to allow FPGA to read SRAM */
	GPIO_PinOutClear(gpioPortD, 9);
}