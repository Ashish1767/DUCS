input_dict={'hilarious': 'amusing','suspicious':'doubtful','comical':'amusing'}
def invert_dict(input_dict):
    output_dict={}
    for k,v in input_dict.items():
        if v not in output_dict:
            output_dict[v] = [k]
        else:
            output_dict[v].append(k)
    print(output_dict)
invert_dict(input_dict)