if (target == NULL) return NULL;

// Check if identifier is array dirctionary or enum
if (target->type->stype->array == NULL) {
    error(CANNOT_GETTING_MEMBER,
        merge(4, token(target->name), " is type ", token(target->type->code), " cannot getting member"),
        location_plus(target->location, location));
    return NULL;
} else if (target->type->stype->array != NULL && !type_compare(type_create(string_create(TYPE_INT), NULL), value->type)) {
    error(ARRAY_GETTING_MEMBER,
        merge(5, token(target->name), " is type ", token(target->type->code), " only getting member by an ", token("int")),
        location_plus(target->location, location));
    return NULL;
}
// Dictionary checking

# new niden type target->type->stype->array->type location location_plus(target->location,location) attach target->attach
niden->name = merge(4, target->name, "[", expr_name(value), "]");
niden->gname = merge(4, target->gname, "[", expr_string(value), "]");

return niden;