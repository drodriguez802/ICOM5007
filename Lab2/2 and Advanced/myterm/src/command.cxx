#include "command.h"
#include <iostream>
#include <boost/xpressive/xpressive.hpp>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <sys/sysinfo.h>
#include <ctime>
DIR* dpdf;
struct dirent* epdf;
using namespace boost::xpressive;

command::command()
    : exit_requested_(false)
{
}
bool command::readline()
{

    std::cout << "@> ";
    std::string in;
    std::getline(std::cin, in);
    parse_line(in);
    return true;
}

void command::print_usage() const
{
}
void command::execute()
{
    std::string cmd = this->parameters_[0];
    if (cmd == "exit") {
        this->exit_requested_ = true;
    }
    else if (cmd == "quiensoy") {
        char username[LOGIN_NAME_MAX];
        getlogin_r(username, LOGIN_NAME_MAX);
        std::cout << username << std::endl;
    }
    else if (cmd == "quedir") {
	char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            std::cout << cwd << std::endl;
    }
    else if (cmd == "lista") {
        dpdf = opendir("./");
        if (dpdf != NULL) {
            while (epdf = readdir(dpdf)) {
                std::cout << epdf->d_name << std::endl;
            }
        }
        closedir(dpdf);
    }
    else if (cmd == "fecha") {
        time_t now = time(0);
        char* dt = ctime(&now);
        std::cout << dt << std::endl;
    }
    else if (cmd == "prendida") {

        struct sysinfo info;
        sysinfo(&info);
        std::cout << info.uptime / 3600 << " hr(s) : " << info.uptime % 3600 / 60 << " min(s)" << std::endl;
    }
	else if (cmd == "history") {
	if(parameters_.size()==2){
		int i = 0;
		std::stringstream convert(parameters_[1]);
		convert >> i;
		std::cout << "I ES : "<< i << std::endl;
		if(i>=history_.size()||i<0){
		std::cout<< "The entry does not exists in history"<<std::endl;
	    	}
		else{
		std::cout << "COMMANDO ES : "<< history_[i] << std::endl;
			parameters_.clear();
			parse_line(history_[i]);
			execute();		
		}
	}
	else if(parameters_.size()==1){
		for (int i=0; i<history_.size();i++){
	    		std::cout << i <<" : " << history_[i] << std::endl;
		}
	}
	}
	else if(cmd=="help"){
		std::cout <<"LIST OF COMMANDS: "<<std::endl;
		std::cout <<"quiensoy : displays the hostname"<<std::endl;
		std::cout <<"quedir : dsplays the current directory"<<std::endl;
		std::cout <<"lista : displays all the archives in the current directory"<<std::endl;
		std::cout <<"fecha : displays date and time"<<std::endl;
		std::cout <<"prendida : displays the time since the system was powered for that specific session"<<std::endl;
		std::cout <<"history / history N : displays the a list of the previous commands, valid or invalid. Adding a digit as a parameter allows the user to execute the N-th command on the list."<<std::endl;

	}
    else {
        std::cout << cmd << " : comando no existe" << std::endl;
    }
    history_.push_back(cmd);
    parameters_.clear();
}
bool command::parse_line(const std::string& line)
{
    

  sregex rex = sregex::compile("(\\w+)");
  sregex_iterator getIn(line.begin(), line.end(), rex), end;
  for (; getIn != end; ++getIn){
    parameters_.push_back((*getIn)[0].str());
  }
  return true;

}