#pragma once
#include "CResource.h"

class LineMesh :
    public CResource
{
public:
    LineMesh();
    virtual ~LineMesh() override;

    void Save(wstring Path);
    void Load(wstring Path);

    vector<pair<POINT, POINT>>& GetLines() { return _lines; }

protected:
    vector<pair<POINT, POINT>> _lines;
};

