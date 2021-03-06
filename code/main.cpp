#include "util.cpp"
#include "part1.cpp"
#include "part2.cpp"

//input/output code
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	srand(time(NULL));

	//read input
	Input input;
	readInput(input, cin);

	//read command line args
	string algorithm = "";
	if(argc > 1) {
		algorithm = argv[1];
	}
		
	//solve problem
	cerr << "using algorithm " << algorithm << endl;
	if(algorithm == "naive") {
		assignrides(input);
		log();
	}
	else {
		cerr << "unknown algorithm" << endl;
		return 1;
	}
	
	//print output
	for(int i = 0; i < input.f; i++) {
		cout << input.paths[i].size();
		for(int j: input.paths[i]) {
			cout << ' ' << j;
		}
		cout << endl;
	}
};
