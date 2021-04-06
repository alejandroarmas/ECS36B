#ifndef SVG_H
#define SVG_H

#include <list>
#include <fstream>
#include <sstream>
#include <iostream>


class SVG {

public:
    SVG(std::string filename = "template.svg") : 
            svg_template_file_name(filename),
            templateLineUnchanged(true),
            template_line("<!-- shapes from the input to be added here -->") {
                line_to_edit = data.begin();
            }
    void grabDataFromFile();
    void printData();
    void insertData(const std::string & new_line);
    

private:
    std::list<std::string> data;
    std::list<std::string>::iterator line_to_edit;
    const std::string svg_template_file_name;    
    const std::string template_line;
    bool templateLineUnchanged;
    
};


void SVG::grabDataFromFile() {
    
    std::fstream fs;
    std::stringstream ss;
    std::string line;
    bool hitTemplateLine = false;


    fs.open(svg_template_file_name, std::fstream::in);
    bool ableToReadFile = fs && line_to_edit == data.begin();
    
    if (ableToReadFile) {

        while (getline(fs, line)) {
            
            data.push_back(line);

            if (!hitTemplateLine && *line_to_edit != template_line) {
                line_to_edit++;
            }
        }

        fs.close();

    }

}


void SVG::insertData(const std::string & new_line) {

    if (templateLineUnchanged) {
        std::string & s( *line_to_edit );
        s = new_line;
        templateLineUnchanged = false;
        line_to_edit++;
    }
    else {
        data.insert(line_to_edit, new_line);
    }
}


void SVG::printData() {

    for (std::list<std::string>::iterator it=data.begin(); it != data.end(); it++) {
                std::cout << *it << std::endl;
            }
}



#endif