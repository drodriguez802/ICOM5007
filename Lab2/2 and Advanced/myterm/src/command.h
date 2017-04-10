#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <vector>
class command
{
private:
  bool exit_requested_;
  std::vector<std::string> parameters_;
  std::vector<std::string> history_;

public:
	command();
	const bool exit_requested() const {
		 return this->exit_requested_; 
	}
	bool readline();
	bool parse_line(const std::string& line);
	void print_usage() const;
	void execute();
};
#endif // COMMAND_H
