#pragma once

#include "JsonNode.h"
class JsonValue;

class JsonNodeWrapper
{
    friend JsonValue;

public:
    JsonNodeWrapper()
        : _node(0)
    {
    }

    explicit JsonNodeWrapper(JsonNode* node)
        : _node(node)
    {
    }

protected:

    void duplicate(const JsonNodeWrapper& other)
    {
        if (!_node)
        {
            _node = other._node;
        }
        else
        {
            _node->duplicate(other._node);
        }
    }

    JsonNode* _node;
};

