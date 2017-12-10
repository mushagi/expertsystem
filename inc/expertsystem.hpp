/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:42:24 by mmayibo           #+#    #+#             */
/*   Updated: 2017/12/04 15:52:21 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERTSYSTEM_HPP
#define EXPERTSYSTEM_HPP
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "../src/main/models/Node.h"
#include "../src/main/models/Nodes.h"
#include "../src/main/models/Rule.h"
#include "../src/main/models/Rules.h"
#include "../src/main/models/Query.h"
#include "../src/main/engine/InferenceEngine.h"
//int validate_query(vector<Node> nodes, vector<Rule> rules, Query query);
string eraseAllWhiteSpaces(string str);
int rpnCalculater(string rpnString);
int string_split(string str, vector<string> *splitArray); 
#endif
