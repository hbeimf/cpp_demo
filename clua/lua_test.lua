-- file: lua_test.lua  
function domain(i)  
  
    -- call C function.  
    local tab = gettab()   
  
    -- show key and value  
    for k, v in pairs(tab) do  
        print("key: ".. k)  
        print("val: ".. v)  
    print()  
    end  
  
end  