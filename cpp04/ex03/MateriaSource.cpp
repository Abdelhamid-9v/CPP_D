#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    copyTemplates(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        clearTemplates();
        copyTemplates(other);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    clearTemplates();
}

void MateriaSource::clearTemplates() {
    for (int i = 0; i < 4; i++) {
        if (templates[i] != NULL) {
            delete templates[i];
            templates[i] = NULL;
        }
    }
}

void MateriaSource::copyTemplates(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
        if (other.templates[i] != NULL) {
            templates[i] = other.templates[i]->clone();
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL)
        return;
    
    for (int i = 0; i < 4; i++) {
        if (templates[i] == NULL)
        {
            templates[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] != NULL && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return NULL;
}