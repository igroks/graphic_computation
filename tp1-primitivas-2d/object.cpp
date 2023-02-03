/*
    Aluno: Igor Carvalho da Silva  
    Email: igor.carvalho@icomp.ufam.edu.br
*/
#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

vector<tuple<float,float>> vertices;
vector<vector<int>> faces;

vector<string> split(string str, string delimiter){
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    tokens.push_back(str);
    return tokens;
}

void render(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    for(int i = 0; i < faces.size(); i++){
        glBegin(GL_POLYGON);
        for(int j = 0; j < faces[i].size(); j++){
            glVertex2f(get<0>(vertices[faces[i][j]-1]),get<1>(vertices[faces[i][j]-1]));
        }
        glEnd();
    }
    glFlush();

}

int main(int argc, char **argv){
    string file_name = "object.txt", line;
    ifstream file; file.open(file_name);
    vector<string> tokens;
    vector<int> face;

    if(!file.is_open()) {
        cout << "File " << file_name << " not found." << endl;
        exit(-1);
    }

    while(getline(file,line)){
        if(line[0] == 'v'){
            tokens = split(line, " ");
            vertices.push_back(make_tuple(stof(tokens[1]),stof(tokens[2])));
            
        }else if(line[0] == 'f'){
            tokens = split(line, " ");
            for(int i = 1; i < tokens.size(); i++){
               face.push_back(atoi(tokens[i].c_str()));
            }
            faces.push_back(face);
        }
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 740);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My Object");
    glutDisplayFunc(render);
    glutMainLoop();
};
