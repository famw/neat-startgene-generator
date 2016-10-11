#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		std::cout << "Usage: ./generator [input_radius] [num_outputs]" << std::endl;
		exit(0);
	}

	int input_radius = std::stoi(argv[1]);
	int num_outputs = std::stoi(argv[2]);

	std::ofstream output_file("neat_startgenes");
	output_file << "genomestart 1\n"; // start of file
	output_file << "trait 1 0 0 0 0 0 0 0 0\n"; // not used but needed

	// nodes
	int num_inputs = (input_radius*2+1)*(input_radius*2+1);
	for(int i=1; i<=num_inputs+1+num_outputs; i++)
	{
		if(i <= num_inputs) // input nodes
		{
			output_file << "node " << i << " 0 1 1\n";
		}
		else if(i == num_inputs+1) // bias node
		{
			output_file << "node " << i << " 0 1 3\n";
		}
		else // output nodes
		{
			output_file << "node " << i << " 0 0 2\n";
		}
	}

	// genes
	int innovation_num = 1;
	for(int in=1; in<=num_inputs+1; in++)
	{
		for(int out=1; out<=num_outputs; out++)
		{
			int out_num = num_inputs+1+out;
			output_file << "gene 1 " << in << " " << out_num << " 0.0 0 " << innovation_num << " 0 1\n";
			innovation_num++;
		}
	}

	output_file << "genomeend 1"; // end of file
	output_file.close();

	return 0;
}
