//=============================================
// @brief Header file for ModelBase class.
//=============================================

#ifndef INCLUDED_MVCMODEL_MODELBASE_HPP
#define INCLUDED_MVCMODEL_MODELBASE_HPP

#include <memory>

namespace game {
namespace MVCmodel {

class ModelBase
{
protected:

public:
	using ShrPtr = std::shared_ptr<ModelBase>;

	ModelBase(void);

	virtual ~ModelBase(void);
};

}} // namespace game::MVCmodel

#endif // INCLUDED_MVCMODEL_MODELBASE_HPP
