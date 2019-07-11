#include "Network.h"
#include "random.h"
#include "Simulation.h"
#include <iostream>
#include "Tclap.h"

/*!
 * \mainpage Network Simulation - A Simple Model of Spiking Neuron
 * 
 * This program aims to simulate a network of neurons based on Izhikevich's work - Simple Model of Spiking Neurons
 * \n You can see his work following this link : http://www.izhikevich.org/publications/spikes.htm
 * \section installation_sec Installation
 * \subsection requirements Requirements
 * In order to run properly on your environment, you need to have installed : \n
 *		\> Cmake, to be able to compile and build the project \n
 * 		\> the tclap library, needed to execute the main part of the project \n
 * 		\> the gtest library, needed to execute tests part of the project \n
 * 		\> R software, to be able to generate the different plot files \n
 * 		\> MatLab, to generate the phase plot file \n
 * 
 * \subsection step1 Step 1 : Downloading and opening the box
 * After downloading the project file, move it to the desired location on your environment. \n
 * Access to the file directory using the terminal. When in the project directory  (called \b Team_21  ) create a new directory named \a build \a . \n
 * \subsection step2 Step 2 : Build the program
 * Go inside the newly created \a build directory and write down the command : <tt> cmake .. </tt>  in the terminal. \n
 * Then run the command :  <tt> make </tt> to build the executables. \n 
 * \subsection step3 Step 3 : Run the program 
 * To run the simulation with default values, just enter : <tt> ./Team_21 </tt> (the executable of the simulation) \n
 * <em> For futher options, see the pdf file included the project. </em> \n
 * After running the simulation, you have to generate raster plot and other visualization curves yourself. \n
 * To create them, go to the output directory and run : <tt> RScript RasterPlots.R raster_data.txt neuron_potential.txt neuron_params.txt </tt> \n
 * To generate the phase plot , Open <em> UV_plots.m </em> with Matlab and go to the <em> output/ </em> folder path in Matlab and run the matlab script \n
 * Plot files should be created in the output directory
 * 
 * \authors B.Delecourt, A.Piguet, A.Bouillon, A.Hammi, L.Musumeci
 * */

RandomNumbers RNG;

int main(int argc , char** argv){
	
	Tclap tclap(argc, argv);

	Simulation sim(tclap.getSteps(), tclap.getNeurons(), tclap.getConnectivity(), tclap.getExcitator(), tclap.getFS(), tclap.getRS(), tclap.getIB(), tclap.getExtension());
	
	sim.run();
		
	return 0;
}
