function get_dependency_path(name)
  -- ObTools standard --
  if name == 'ot-xmlmesh-core' then
    return 'obtools/xmlmesh/core'
  elseif name == 'ot-xmlmesh-send' then
    return 'obtools/xmlmesh/bindings/cli/send'
  elseif name == 'ot-xmlmesh-receive' then
    return 'obtools/xmlmesh/bindings/cli/receive'
  elseif string.sub(name, 1, 11) == 'ot-xmlmesh-' then
    return 'obtools/xmlmesh/' .. string.sub(name, 12)
  elseif name == 'ot-toolgen' then
    return 'obtools/tools/toolgen'
  elseif string.sub(name, 1, 11) == 'ot-obcache-' then
    return 'obtools/obcache/libs/' .. string.sub(name, 12)
  elseif string.sub(name, 1, 3) == 'ot-' then
    return 'obtools/libs/' .. string.sub(name, 4)

  -- Our libraries --
  elseif string.sub(name, 1, 4) == 'mdz-' then
    return 'libs/' .. string.sub(name, 5)

  end
  return nil
end
